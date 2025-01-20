OutFile "SerialDataVisualizerSetup.exe"

InstallDir "$PROGRAMFILES\SerialDataVisualizer"
InstallDirRegKey HKLM "Software\SerialDataVisualizer" "Install_Dir"

Name "Serial Data Visualizer Application" ;

!include "MUI2.nsh"


!define MUI_WELCOMEPAGE_TITLE "Welcome to the Serial Data Visualizer Setup"
!define MUI_WELCOMEPAGE_TEXT "Setup will guide you through the installation of Serial Data Visualizer Application. It is recommended that you close all other applications before starting Setup. This will make it possible to update relevant system files without having to reboot your computer. Click Next to continue."

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Section "Install"
    SetOutPath $INSTDIR
    File /r "C:\Users\Thinkpad\Documents\QT_Programing\serial_data_visualizer\installer\serial_data_visualizer_windows\*" 
    CreateDirectory "$SMPROGRAMS\SerialDataVisualizer"
    CreateShortCut "$SMPROGRAMS\SerialDataVisualizer\Serial Data Visualizer.lnk" "$INSTDIR\serial_data_visualizer_qt.exe"
    CreateShortCut "$DESKTOP\Serial Data Visualizer.lnk" "$INSTDIR\serial_data_visualizer_qt.exe"
SectionEnd

Section "Uninstall"
    Delete "$INSTDIR\serial_data_visualizer_qt.exe"
    Delete "$SMPROGRAMS\SerialDataVisualizer\Serial Data Visualizer.lnk"
    Delete "$DESKTOP\Serial Data Visualizer.lnk"
    RMDir /r "$INSTDIR"
    RMDir "$SMPROGRAMS\SerialDataVisualizer"
SectionEnd
