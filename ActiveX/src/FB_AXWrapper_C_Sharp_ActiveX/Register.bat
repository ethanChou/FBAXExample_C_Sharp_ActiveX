@echo on

REM 管理员运行注册
REM $WINDIR\Microsoft.NET\Framework\v4.0.30319\RegAsm.exe "%cd%\IcpActiveXControls.dll" /unregister

REM 显示路径信息
echo %cd%\FB_AXWrapper_C_Sharp_ActiveX.dll

REM 注册插件
%WINDIR%\Microsoft.NET\Framework\v4.0.30319\RegAsm.exe /codebase "%cd%\FB_AXWrapper_C_Sharp_ActiveX.dll"

REGSVR32 "%cd%\lib\npaxsamplectrl.dll"

pause