#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS
EFIAPI
PmicProtocolStubDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;
  EFI_HANDLE  Handle;
  EFI_GUID    PmicProtocolGuid = { 0xae37b942, 0x457f, 0x4c91,
                                   { 0xa1, 0x96, 0xd9, 0x66, 0x9f, 0xd3, 0x47, 0xa3 } };

  Handle = NULL;
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Handle,
                  &PmicProtocolGuid,
                  NULL,
                  NULL
                  );
  DEBUG ((DEBUG_ERROR, "[PMICSTUB] Install ae37b942 -> %r\n", Status));
  return Status;
}
