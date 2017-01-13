/**********************************************************\

  Auto-generated axsamplectrlAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "axsamplectrl.h"

#ifndef H_axsamplectrlAPI
#define H_axsamplectrlAPI

class axsamplectrlAPI : public FB::JSAPIAuto
{
public:
    axsamplectrlAPI(const axsamplectrlPtr& plugin, const FB::BrowserHostPtr& host);
    virtual ~axsamplectrlAPI();

    axsamplectrlPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
   	void Say(const std::string& msg);

	std::string SendMessage(int id, const std::string& msg);
    
    // Event helpers
    FB_JSAPI_EVENT(FireCompleted, 2, (const std::string&, const std::string&));
  

private:
    axsamplectrlWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
};

#endif // H_axsamplectrlAPI

