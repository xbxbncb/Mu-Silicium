#include <Uefi.h>
#include <Library/DebugLib.h>

STATIC
VOID
Walk (
  IN UINT64  Va
  )
{
  UINT64  Ttbr0;
  UINT64  Tcr;
  UINT64  Mair;
  UINT64  Desc;
  UINT64  Table;
  UINT64  Idx;
  UINT64  Pa;
  INT32   Level;
  INT32   Idx32;

  __asm__ __volatile__ ("mrs %0, ttbr0_el1" : "=r" (Ttbr0));
  __asm__ __volatile__ ("mrs %0, tcr_el1" : "=r" (Tcr));
  __asm__ __volatile__ ("mrs %0, mair_el1" : "=r" (Mair));
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] VA=%lx TTBR0=%lx TCR=%lx MAIR=%lx\n",
    Va, Ttbr0, Tcr, Mair));

  Desc   = 0;
  Table  = Ttbr0 & 0x0000FFFFFFFFFFF000ULL;
  Level  = 0;
  for (Level = 1; Level <= 3; Level++) {
    Idx   = (Va >> (30 - 9 * (Level - 1))) & 0x1FF;
    Idx32 = (INT32)Idx;
    Desc  = *(volatile UINT64 *)(Table + Idx * 8);
    DEBUG ((DEBUG_ERROR, "[SPMIPROBE] L%d[%d] @%lx = %lx\n",
      Level, Idx32, Table + Idx * 8, Desc));
    if ((Desc & 1ULL) == 0) {
      DEBUG ((DEBUG_ERROR, "[SPMIPROBE] UNMAPPED at L%d\n", Level));
      return;
    }
    if ((Desc & 2ULL) == 0) {
      break;
    }
    Table = Desc & 0x0000FFFFFFFFFFF000ULL;
  }
  if (Level > 3) {
    DEBUG ((DEBUG_ERROR, "[SPMIPROBE] unexpected table at L3\n"));
    return;
  }
  if (Level == 1) {
    Pa = (Desc & 0x0000FFFFC0000000ULL) | (Va & 0x3FFFFFFFULL);
  } else if (Level == 2) {
    Pa = (Desc & 0x0000FFFFFFE00000ULL) | (Va & 0x1FFFFFULL);
  } else {
    Pa = (Desc & 0x0000FFFFFFFFF000ULL) | (Va & 0xFFFULL);
  }
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] L%d block: PA=%lx AttrIdx=%d AP=%d SH=%d AF=%d nG=%d\n",
    Level, Pa,
    (INT32)((Desc >> 2) & 7),
    (INT32)((Desc >> 6) & 3),
    (INT32)((Desc >> 8) & 3),
    (INT32)((Desc >> 10) & 1),
    (INT32)((Desc >> 11) & 1)));
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] MAIR[AttrIdx]=%x\n",
    (INT32)((Mair >> (((Desc >> 2) & 7) * 8)) & 0xFF)));
}

STATIC
UINT32
Read32 (
  IN UINT64  Addr
  )
{
  UINT32  Value;

  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] read %lx ...\n", Addr));
  Value = *(volatile UINT32 *)Addr;
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE]   -> %x\n", Value));
  return Value;
}

EFI_STATUS
EFIAPI
SpmiProbeDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] ===== ENTRY =====\n"));

  Walk (0x000000000C717008ULL);

  Read32 (0x000000000C42D000ULL);
  Read32 (0x000000000C42D004ULL);
  Read32 (0x000000000C400000ULL);
  Read32 (0x000000000C500000ULL);
  Read32 (0x000000000C500008ULL);
  Read32 (0x000000000C4C0000ULL);
  Read32 (0x000000000C717008ULL);

  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] ===== ALL READS DONE =====\n"));
  return EFI_SUCCESS;
}
