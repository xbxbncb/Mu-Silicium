#include <Uefi.h>
#include <Library/DebugLib.h>

STATIC
VOID
WalkCompact (
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

  __asm__ __volatile__ ("mrs %0, ttbr0_el1" : "=r" (Ttbr0));
  __asm__ __volatile__ ("mrs %0, tcr_el1" : "=r" (Tcr));
  __asm__ __volatile__ ("mrs %0, mair_el1" : "=r" (Mair));
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] TTBR0=%lx TCR=%lx MAIR=%lx\n", Ttbr0, Tcr, Mair));

  Desc   = 0;
  Table  = Ttbr0 & 0x0000FFFFFFFFFFF000ULL;
  Level  = 0;
  for (Level = 1; Level <= 3; Level++) {
    Idx   = (Va >> (30 - 9 * (Level - 1))) & 0x1FF;
    Desc  = *(volatile UINT64 *)(Table + Idx * 8);
    if ((Desc & 1ULL) == 0) {
      DEBUG ((DEBUG_ERROR, "[SPMIPROBE] VA=%-10lx UNMAPPED at L%d\n", (UINT64)Va, Level));
      return;
    }
    if ((Desc & 2ULL) == 0) {
      break;
    }
    Table = Desc & 0x0000FFFFFFFFFFF000ULL;
  }
  if (Level == 3 && (Desc & 2ULL)) {
    DEBUG ((DEBUG_ERROR, "[SPMIPROBE] VA=%-10lx L3 still table\n", (UINT64)Va));
    return;
  }
  if (Level == 1) {
    Pa = (Desc & 0x0000FFFFC0000000ULL) | (Va & 0x3FFFFFFFULL);
  } else if (Level == 2) {
    Pa = (Desc & 0x0000FFFFFFE00000ULL) | (Va & 0x1FFFFFULL);
  } else {
    Pa = (Desc & 0x0000FFFFFFFFF000ULL) | (Va & 0xFFFULL);
  }
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] VA=%-10lx L%d final=0x%lx AttrIdx=%-d AP=%-d SH=%-d AF=%-d nG=%-d MAIRbyte=0x%x\n",
    (UINT64)Va, Level, Pa,
    (INT32)((Desc >> 6) & 3), (INT32)((Desc >> 8) & 3),
    (INT32)((Desc >> 10) & 1), (INT32)((Desc >> 11) & 1),
    (INT32)((Mair >> (((Desc >> 2) & 7) * 8)) & 0xFF)));
}

STATIC
UINT32
Read32 (
  IN UINT64  Addr
  )
{
  UINT32  Value;

  Value = *(volatile UINT32 *)Addr;
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] r%-10lx=0x%08x\n", (UINT64)Addr, Value));
  return Value;
}

EFI_STATUS
EFIAPI
SpmiProbeDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] ENTRY\n"));
  WalkCompact (0x000000000C717008ULL);
  WalkCompact (0x000000000C500000ULL);
  Read32 (0x000000000C42D000ULL);
  Read32 (0x000000000C42D004ULL);
  Read32 (0x000000000C400000ULL);
  Read32 (0x000000000C400004ULL);
  Read32 (0x000000000C4C0000ULL);
  Read32 (0x000000000C440000ULL);
  Read32 (0x000000000C500000ULL);
  Read32 (0x000000000C500008ULL);
  DEBUG ((DEBUG_ERROR, "[SPMIPROBE] DONE\n"));
  return EFI_SUCCESS;
}
