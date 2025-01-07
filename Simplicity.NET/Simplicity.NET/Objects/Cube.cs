using System.Runtime.InteropServices;

namespace Simplicity.NET.Objects
{
    public class Cube : Drawable
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Cube_create(Vector3 position);

        public Cube(Vector3 position) : base(Cube_create(position))
        {
        }
    }
}
