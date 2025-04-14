using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public class Texture2D
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Texture2D_create(string filename);

        IntPtr _texture2D;
        internal IntPtr GetPtr()
        {
            return _texture2D;
        }

        /// <param name="filepath">Filepath has to be a full path!</param>
        public Texture2D(string filepath)
        {
            _texture2D = Texture2D_create(filepath);
        }
    }
}
