@echo on

REM ����Ա����ע��
REM $WINDIR\Microsoft.NET\Framework\v4.0.30319\RegAsm.exe "%cd%\IcpActiveXControls.dll" /unregister

REM ��ʾ·����Ϣ
echo %cd%\FB_AXWrapper_C_Sharp_ActiveX.dll

REM ע����
%WINDIR%\Microsoft.NET\Framework\v4.0.30319\RegAsm.exe /codebase "%cd%\FB_AXWrapper_C_Sharp_ActiveX.dll"

REGSVR32 "%cd%\lib\npaxsamplectrl.dll"

pause