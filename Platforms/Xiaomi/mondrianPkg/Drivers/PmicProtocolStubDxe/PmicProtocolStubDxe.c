#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>

//
// ae37b942-457f-4c91-a196-d9669fd347a3  (LE bytes: 42 b9 37 ae 7f 45 91 4c a1 96 d9 66 9f d3 47 a3)
//
#define EFI_PMIC_PROTOCOL_STUB_GUID  \
  { 0xae37b942, 0x457f, 0x4c91, { 0xa1, 0x96, 0xd9, 0x66, 0x9f, 0xd3, 0x47, 0xa3 } }

EFI_GUID  gPmicProtocolStubGuid = EFI_PMIC_PROTOCOL_STUB_GUID;

EFI_STATUS
EFIAPI
PmicProtocolStubDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;
  EFI_HANDLE  Handle;

  Handle = NULL;
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Handle,
                  &gPmicProtocolStubGuid,
                  NULL,
                  NULL
                  );
  DEBUG ((DEBUG_ERROR, "[PMICSTUB] Install ae37b942 -> %r\n", Status));
  return Status;
}
