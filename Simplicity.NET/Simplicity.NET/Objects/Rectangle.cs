using System.Runtime.InteropServices;

namespace Simplicity.NET.Objects
{
    public class Rectangle : Drawable
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Rectangle_create(float x, float y, float width, float height);

        public Rectangle(float x, float y, float width, float height) : base(Rectangle_create(x, y, width, height))
        {
        }
    }
}
