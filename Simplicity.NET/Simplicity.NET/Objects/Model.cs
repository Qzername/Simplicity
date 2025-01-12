using System.Runtime.InteropServices;

namespace Simplicity.NET.Objects
{
    public class Model : Drawable
    {
        public Model(string filename) : base(Model_create(filename))
        {
        }

        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Model_create(string filename);
    }
}
