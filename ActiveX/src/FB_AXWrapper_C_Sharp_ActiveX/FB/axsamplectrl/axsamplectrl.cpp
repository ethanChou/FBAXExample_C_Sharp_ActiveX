/**********************************************************\

  Auto-generated axsamplectrl.cpp

  This file contains the auto-generated main plugin object
  implementation for the axsamplectrl project

\**********************************************************/

#include "axsamplectrlAPI.h"

#include "axsamplectrl.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn axVideoPlayer::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void axsamplectrl::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process
}

///////////////////////////////////////////////////////////////////////////////
/// @fn axVideoPlayer::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void axsamplectrl::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded 
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  axVideoPlayer constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
axsamplectrl::axsamplectrl():m_axwin(this)
{
	m_WindowAttached = false;
	m_PlugInReady = false;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  axVideoPlayer destructor.
///////////////////////////////////////////////////////////////////////////////
axsamplectrl::~axsamplectrl()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void axsamplectrl::onPluginReady()
{
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
	if(m_PlugInReady == false)
	{
		m_PlugInReady = true;
		if(m_WindowAttached)
			CreateAxWindow();
	}
}



///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<axVideoPlayer> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr axsamplectrl::createJSAPI()
{
    // m_host is the BrowserHost
    m_axwrapperapi = boost::make_shared<axsamplectrlAPI>(FB::ptr_cast<axsamplectrl>(shared_from_this()), m_host);
    return m_axwrapperapi;
}

bool axsamplectrl::setReady()
{
	 // The call to getRootJSAPI() was removed from PluginCore::setReady() between version
	 // 1.5 and 1.6. Without this call, the plugin JSAPI object may not get created unless
	 // the html <object> tag includes an "onload" param. This plugin relies on the pointer
	 // to the JSAPI object being valid in order to fire events.

    // Ensure that the JSAPI object has been created, in case the browser hasn't requested it yet.
    getRootJSAPI(); 
	 return PluginCore::setReady();
}

bool axsamplectrl::onWindowsMessage(FB::WindowsEvent *evt, FB::PluginWindowWin *piw)
{
	bool rc = false;
	if(!m_axwin)
		return false;
	switch(evt->uMsg)
	{
		case WM_SIZE:
			// resize the ActiveX container window
			m_axwin.MoveWindow(0, 0, LOWORD(evt->lParam), HIWORD(evt->lParam));
			evt->lRes = 0;
			rc = true;
			break;
		case WM_MOUSEACTIVATE:
			// activate on mouse click
			evt->lRes = MA_ACTIVATE;
			rc = true;
			break;
		case WM_SETFOCUS:
			// forward focus to the ActiveX control container window
			m_axwin.SetFocus();
			evt->lRes = 0;
			rc = true;
			break;
	}
	return rc;
}

bool axsamplectrl::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *)
{
    // The window is attached; act appropriately
	if(m_WindowAttached == false)
	{
		m_WindowAttached = true;
		if(m_PlugInReady)
			CreateAxWindow();
	}
    return false;
}

bool axsamplectrl::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    // The window is about to be detached; act appropriately
	 DestroyAxWindow();
    return false;
}


bool axsamplectrl::CreateAxWindow()
{
	try {

		/* Now that we have the plugin window, create the ActiveX container
		   window as a child of the plugin, then create the ActiveX control
			as a child of the container.
		*/
		
		FB::PluginWindowWin* pwnd = static_cast<FB::PluginWindowWin*>(GetWindow());
		if(pwnd != NULL)
		{
			HWND hWnd = pwnd->getHWND();
			if(hWnd)
			{				
				// Create the ActiveX control container
				RECT rc;
				::GetClientRect(hWnd, &rc);
				m_axwin.Create(hWnd, &rc, 0, WS_VISIBLE|WS_CHILD);

				// Create an instance of the ActiveX control in the container. If the ActiveX
				// control requires a license key, change CreateControlEx to CreateControlLicEx
				// and add one more parameter - CComBSTR(AXCTLLICKEY) - to the argument list.
				CComPtr<IUnknown> spControl;
				HRESULT hr = m_axwin.CreateControlEx(AXCTLPROGID, NULL, NULL, &spControl, GUID_NULL, NULL);
				if(SUCCEEDED(hr) && (spControl != NULL))
				{
					// Get the control's default interface
					spControl.QueryInterface(&m_spaxctl);
					if(m_spaxctl)
					{
						// Connect the event sink
						hr = m_axwin.DispEventAdvise((IUnknown*)m_spaxctl);

				
						//int theme = 0;
						//std::string args;
						//try {
						//	theme = m_params["WindowCount"].convert_cast<int>();
						//	SetWindowMode(theme);

						//} catch(...) {} // ignore missing param

						//try {
						//	args = m_params["Parameters"].convert_cast<std::string>();
						//	SetParameters(args);

						//} catch(...) {} // ignore missing param

						//m_axwrapperapi->fire_load();

						return true;
					}
				}
			}
		}
	} catch(...) {
		//TODO: should we throw a FB exception here?
	}
	return false;
}

void axsamplectrl::DestroyAxWindow()
{
	if(m_spaxctl)
	{
		// Disconnect the event sink
		m_axwin.DispEventUnadvise((IUnknown*)m_spaxctl);		
		// Kill reference to the ActiveX control - when the plugin
		// window is destroyed, the container & control will be
		// automatically destroyed.
		m_spaxctl = NULL;
		m_WindowAttached=false;
	}
}

void axsamplectrl::Say(const std::string& msg)
{
	if(m_spaxctl)
	{
		try {
			HRESULT hr = m_spaxctl->Say(CComBSTR(FB::utf8_to_wstring(msg).c_str()));
		    if(SUCCEEDED(hr))
			{
			}
		}
		catch(...) {
		}
	}
}

std::string axsamplectrl::SendMessage( int id, const std::string& msg)
{
	if(m_spaxctl)
	{
		try {
			CComBSTR bstr;
			HRESULT hr = m_spaxctl->SendMessage(id,CComBSTR(FB::utf8_to_wstring(msg).c_str()),&bstr);
		    if(SUCCEEDED(hr))
			{
				return FB::wstring_to_utf8(std::wstring(bstr.m_str, bstr.Length()));
			}
		}
		catch(...) {
		}
	}
	return std::string();
}


