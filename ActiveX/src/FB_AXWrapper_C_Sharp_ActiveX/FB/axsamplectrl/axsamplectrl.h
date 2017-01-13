/**********************************************************\

  Auto-generated axsamplectrl.h

  This file contains the auto-generated main plugin object
  implementation for the axsamplectrl project

\**********************************************************/
#ifndef H_axsamplectrlPLUGIN
#define H_axsamplectrlPLUGIN

#include "PluginWindow.h"
#include "Win\PluginWindowWin.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"
#include "PluginEvents/WindowsEvent.h"

#include "PluginCore.h"

// Forward declare
class axsamplectrlAPI;

#include "axsamplectrlWin.h" // we need class definition for axWrapperAxWin

FB_FORWARD_PTR(axsamplectrl)

class axsamplectrl : public FB::PluginCore
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    axsamplectrl();
    virtual ~axsamplectrl();

public:
    void onPluginReady();
    //void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    // If you want your plugin to always be windowless, set this to true
    // If you want your plugin to be optionally windowless based on the
    // value of the "windowless" param tag, remove this method or return
    // FB::PluginCore::isWindowless()
    virtual bool isWindowless() { return false; }
	virtual bool setReady(); // override this so we can ensure that createJSAPI() gets called!

    BEGIN_PLUGIN_EVENT_MAP()
	    EVENTTYPE_CASE(FB::WindowsEvent, onWindowsMessage, FB::PluginWindowWin)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
	virtual bool onWindowsMessage(FB::WindowsEvent *evt, FB::PluginWindowWin *);
    virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
    virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/
public:

	// ActiveX control methods

	void Say(const std::string& msg);

	std::string SendMessage(int id, const std::string& msg);

	// provide access to JSAPI functions
    typedef boost::shared_ptr<axsamplectrlAPI> axsamplectrlAPIPtr;
	axsamplectrlAPIPtr getJSAPI() {return m_axwrapperapi;}

private:

	FB::BrowserHostPtr getHost() {return m_host;}

	// ActiveX control initialization
	bool InitializeAxControl();
	bool CreateAxWindow();
	void DestroyAxWindow();

	// Flags to ensure we wait until both onPlugInReady & onWindowAttached
	// have been called before creating the CAxWindow.
	bool m_WindowAttached;
	bool m_PlugInReady;

	axsamplectrlAPIPtr m_axwrapperapi; // easy access to JSAPI functions
	axsamplectrlWin m_axwin; // ActiveX control container instance (CAxWindow)
	CComPtr<AXCTLDEFINTF> m_spaxctl; // ActiveX control instance


};

typedef boost::shared_ptr<axsamplectrl> axsamplectrlPtr;
typedef boost::weak_ptr<axsamplectrl> axsamplectrlWeakPtr;
#endif

