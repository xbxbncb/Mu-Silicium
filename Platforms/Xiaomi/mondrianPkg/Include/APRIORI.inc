APRIORI DXE {
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF QcomPkg/Drivers/IortDtDxe/IortDtDxe.inf

  INF mondrianPkg/Drivers/SpmiProbeDxe/SpmiProbeDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/EnvDxe/EnvDxe.inf

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/TzDxe/ScmDxeLA.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf

  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf

  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/UFSDxe/UFSDxe.inf

  INF FatPkg/EnhancedFatDxe/Fat.inf

  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/TzDxe/TzDxeLA.inf

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF mondrianPkg/Binaries/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  INF mondrianPkg/Binaries/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  # EXCLUDED: INF mondrianPkg/Binaries/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/XhciDxe/XhciDxe.inf

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF mondrianPkg/Binaries/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
!endif
  INF mondrianPkg/Binaries/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF mondrianPkg/Binaries/QcomPkg/Drivers/RNGDxe/RngDxe.inf

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
}
