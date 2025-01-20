
OutFile "SerialDataVisualizerSetup.exe"


InstallDir "$PROGRAMFILES\SerialDataVisualizer"


InstallDirRegKey HKLM "Software\SerialDataVisualizer" "Install_Dir"


!include "MUI2.nsh"
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Section "Install"
    SetOutPath $INSTDIR
    File /r "C:\Users\Thinkpad\Documents\QT_Programing\serial_data_visualizer\serial_data_visualizer_qt\build\Desktop_Qt_6_2_4_MinGW_64_bit-Debug\debug\serial_data\*"   # Path ke folder deploy Anda
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
