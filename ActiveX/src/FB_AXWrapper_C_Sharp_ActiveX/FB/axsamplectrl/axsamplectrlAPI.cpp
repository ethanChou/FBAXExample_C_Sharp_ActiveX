/**********************************************************\

  Auto-generated axsamplectrlAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "axsamplectrlAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn axsamplectrlAPI::axsamplectrlAPI(const axsamplectrlPtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
axsamplectrlAPI::axsamplectrlAPI(const axsamplectrlPtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host)
{
    registerMethod("Say",      make_method(this, &axsamplectrlAPI::Say));
    registerMethod("SendMessage", make_method(this, &axsamplectrlAPI::SendMessage));

    //// Read-write property
    //registerProperty("testString",
    //                 make_property(this,
    //                    &axsamplectrlAPI::get_testString,
    //                    &axsamplectrlAPI::set_testString));

    //// Read-only property
    //registerProperty("version",
    //                 make_property(this,
    //                    &axsamplectrlAPI::get_version));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn axsamplectrlAPI::~axsamplectrlAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
axsamplectrlAPI::~axsamplectrlAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn axsamplectrlPtr axsamplectrlAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
axsamplectrlPtr axsamplectrlAPI::getPlugin()
{
    axsamplectrlPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}



// Read/Write property testString
std::string axsamplectrlAPI::SendMessage(int id,const std::string& msg)
{
    return getPlugin()->SendMessage(id,msg);
}

void axsamplectrlAPI::Say(const std::string& msg)
{
    getPlugin()->Say(msg);
}


