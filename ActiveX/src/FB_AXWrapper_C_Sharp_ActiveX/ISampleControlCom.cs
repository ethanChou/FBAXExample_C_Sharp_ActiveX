using System.Runtime.InteropServices;

namespace FB_AXWrapper_C_Sharp_ActiveX
{

    [Guid("4FE4F434-E393-4743-ACF3-76F9132B4225")]
    [InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
    public interface ISampleControlCom
    {
        [DispId(0x001)]
        void FireCompleted(string sender, string e);
    }

    [ComVisible(false)]
    public delegate void FireCompletedEventHandler(string sender, string data);
}
