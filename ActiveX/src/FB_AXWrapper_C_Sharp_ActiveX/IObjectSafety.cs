using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace FB_AXWrapper_C_Sharp_ActiveX
{
    [ComImport, GuidAttribute("CB5BDC81-93C1-11CF-8F20-00805F2CD064")]
    [InterfaceTypeAttribute(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IObjectSafety
    {
        [PreserveSig]
        int GetInterfaceSafetyOptions(ref Guid riid, [MarshalAs(UnmanagedType.U4)] ref int pdwSupportedOptions, [MarshalAs(UnmanagedType.U4)] ref int pdwEnabledOptions);

        [PreserveSig()]
        int SetInterfaceSafetyOptions(ref Guid riid, [MarshalAs(UnmanagedType.U4)] int dwOptionSetMask, [MarshalAs(UnmanagedType.U4)] int dwEnabledOptions);
    }

   

    [Guid("08831BB6-FEA7-4EBC-AFA2-BB6C574B0227")]
    [InterfaceTypeAttribute(ComInterfaceType.InterfaceIsIDispatch)]
    public interface IActiveXPlayerX
    {
        /// <summary>
        /// 媒体文件播放结束回调
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        //[DispId(0x001)]
        //void Started(string s);

        [DispId(0xddd0001)]
        void Completed(string s);

        [DispId(0xddd0002)]
        void End(object s);

        //[DispId(0x003)]
        //void KeyPressed(int e);

        //[DispId(0x004)]
        //void KeyUped(string e);
    }

    [ComVisible(false)]
    public delegate void OperationCompletedDel(string message); //No need to expose this delegate


    [ComVisible(false)]
    public delegate void OperationEndDel(object message); //No need to expose this delegate

    //public delegate void KeyPressedEventHandler(Keys key);
}
