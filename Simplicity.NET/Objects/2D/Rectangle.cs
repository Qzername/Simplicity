using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Simplicity.NET.Objects
{
    public class Rectangle : Drawable
    {
        [DllImport("./libs/Simplicity.dll")]
        static extern IntPtr createRectangle(float x, float y, float width, float height);

        public Rectangle(float x, float y, float width, float height)
        {
            drawable = createRectangle(x, y, width, height);
        }
    }
}
