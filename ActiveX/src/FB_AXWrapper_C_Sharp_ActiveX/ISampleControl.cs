using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FB_AXWrapper_C_Sharp_ActiveX
{
    public interface ISampleControl
    {
        void Say(string msg);

        string SendMessage(int id, string msg);
    }
}
