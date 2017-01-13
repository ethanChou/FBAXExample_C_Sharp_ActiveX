/**********************************************************\

\**********************************************************/

#include "axsamplectrlAPI.h"
#include "axsamplectrl.h"
#include "axsamplectrlWin.h"

#ifdef SubclassWindow
#undef SubclassWindow // this is a macro defined in Windowsx.h - it conflicts with ATL CWindow::SubclassWindow function!
#endif

// Define the event function info structures for any events we want
// to catch. These structures are referenced in the event sink map
// used by IDispEventSimpleImpl (see axWrapper.h BEGIN_SINK_MAP).
//_ATL_FUNC_INFO efiClick = {CC_STDCALL, VT_EMPTY, 0, {NULL}};
//_ATL_FUNC_INFO efiKeyPress = {CC_STDCALL, VT_EMPTY, 1, {VT_I2 | VT_BYREF}};

_ATL_FUNC_INFO efiCompleted = {CC_STDCALL, VT_EMPTY, 2, {VT_BSTR,VT_BSTR}};


/**********************************************************\

  implementation for the ActiveX control container class

\**********************************************************/

// ActiveX control event handlers
axsamplectrlWin::axsamplectrlWin()
{
	
}



void __stdcall axsamplectrlWin::onFireCompleted(CComBSTR val,CComBSTR data)
{
	try {
		//MessageBox(val.m_str,L"Title(§¢§ì§¾§ä)",MB_OK);
		std::string m=FB::wstring_to_utf8(std::wstring(val.m_str, val.Length()));
		std::string dt=FB::wstring_to_utf8(std::wstring(data.m_str, data.Length()));

		m_pPlugin->getJSAPI()->fire_FireCompleted(m,dt);
	}
	catch(...)
	{
	}
}



