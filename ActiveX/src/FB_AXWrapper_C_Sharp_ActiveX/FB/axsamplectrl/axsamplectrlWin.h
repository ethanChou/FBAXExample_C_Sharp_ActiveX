/**********************************************************\

\**********************************************************/
#ifndef H_axsamplectrlWIN
#define H_axsamplectrlWIN

#include "PluginWindow.h"
#include "Win\PluginWindowWin.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"
#include "PluginEvents/WindowsEvent.h"
#include "PluginCore.h"
#include <atlwin.h>

// Import the ActiveX control's typelib so we can easily call methods, etc.
// on the ActiveX control.
#import "FB_AXWrapper_C_Sharp_ActiveX.tlb" named_guids,no_namespace, raw_interfaces_only

// Define the ProgID for the ActiveX control.
#define AXCTLPROGID L"FB_AXWrapper_C_Sharp_ActiveX.SampleControl"

// Define the ActiveX control's default & event interfaces. You might
// want to use a type library view like OleView.exe to identify interface
// names. Or you can find them in the registry.
#define AXCTLDEFINTF ISampleControl
#define AXCTLEVTINTF ISampleControlCom

// If the ActiveX control you are wrapping requires a license key,
// define that key here. Check Microsoft knowledge base article
// Q151771 for information on obtaining the license key for an
// ActiveX control.
//#define AXCTLLICKEY L"xxxxxxxxxxxx"

// Event function info structures are defined in axWrapper.cpp
//extern _ATL_FUNC_INFO efiClick;
//extern _ATL_FUNC_INFO efiKeyPress;

extern _ATL_FUNC_INFO efiCompleted;

class axsamplectrl;

/**********************************************************\

 Define the ActiveX control container class using ATL's CAxWindow
 template with event support from ATL's IDispEventSimpleImpl
 tempalte.

 Note: if the ActiveX control that you are wrapping requires a
 license key, use CAxWindow2 instead of CAxWindow.

 \**********************************************************/
class axsamplectrlWin : public CAxWindow, public IDispEventSimpleImpl<1, axsamplectrlWin, &__uuidof(AXCTLEVTINTF)>
{
public:
	axsamplectrlWin();
	axsamplectrlWin(axsamplectrl* pPlugin) : m_pPlugin(pPlugin) {}
	virtual ~axsamplectrlWin() {}

	// Declare the events from the ActiveX control that we want to catch
	// in our FB plugin. See ATL documentation for IDispEventSimpleImpl for
	// details.
	BEGIN_SINK_MAP(axsamplectrlWin)
		SINK_ENTRY_INFO(1, __uuidof(AXCTLEVTINTF), 0x0001, onFireCompleted, &efiCompleted)
	
	END_SINK_MAP()

	// Declare the ActiveX control event handler functions

	void __stdcall onFireCompleted(CComBSTR val,CComBSTR data);
	
	//void __stdcall onKeyPress(short* pKeyCode);

	// Back pointer to containing plugin object (this is not using boost
	// shared_ptr because this object's lifetime is controlled excusively
	// by the plugin object's lifetime).
	axsamplectrl* m_pPlugin; 

};

#endif
