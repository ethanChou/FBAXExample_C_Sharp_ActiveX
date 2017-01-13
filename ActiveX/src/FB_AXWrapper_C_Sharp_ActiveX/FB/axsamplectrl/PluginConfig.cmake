#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for axsamplectrl
#
#\**********************************************************/

set(PLUGIN_NAME "axsamplectrl")
set(PLUGIN_PREFIX "axs")
set(COMPANY_NAME "test")

# ActiveX constants:
set(FBTYPELIB_NAME axsamplectrlLib)
set(FBTYPELIB_DESC "axsamplectrl 1.0 Type Library")
set(IFBControl_DESC "axsamplectrl Control Interface")
set(FBControl_DESC "axsamplectrl Control Class")
set(IFBComJavascriptObject_DESC "axsamplectrl IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "axsamplectrl ComJavascriptObject Class")
set(IFBComEventSource_DESC "axsamplectrl IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 734099d9-142c-5697-a132-faff3e87844c)
set(IFBControl_GUID ab6f4ed6-cbe4-525b-a069-c682fd77a6b2)
set(FBControl_GUID b573b2d8-b307-5304-9fcd-ed0d62548c2c)
set(IFBComJavascriptObject_GUID 83c3199b-4f0d-557b-97bd-d3b4fda21ad3)
set(FBComJavascriptObject_GUID 878f968a-4aac-565a-9bfe-6a24dc52e176)
set(IFBComEventSource_GUID 7b91b376-c416-5fe9-abe8-a5b28cd19f8e)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "test.axsamplectrl")
set(MOZILLA_PLUGINID "test.com/axsamplectrl")

# strings
set(FBSTRING_CompanyName "test")
set(FBSTRING_FileDescription "test")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2017 test")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "axsamplectrl")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "axsamplectrl")
set(FBSTRING_MIMEType "application/x-axsamplectrl")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
