using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics.Objects
{
    public class Texture2D
    {
        [DllImport(LibConsts.LibPath)]
        static extern nint Texture2D_LoadFromFile(string filename);

        [DllImport(LibConsts.LibPath)]
        static extern nint Texture_LoadFromData(int width, int height, byte[] data, TextureFormat textureFormat);

        nint _texture2D;
        internal nint GetPtr()
        {
            return _texture2D;
        }

        internal Texture2D(nint texture2D)
        {
            _texture2D = texture2D;
        }

        public static Texture2D LoadFromFile(string filename)
        {
            return new Texture2D(Texture2D_LoadFromFile(filename));
        }

        /// <param name="data">Raw data of Texture that contains RGB data for every pixel</param>
        public static Texture2D LoadFromData(int width, int height, byte[] data, TextureFormat textureFormat)
        {
            if (data.Length / 3 != width * height)
                throw new Exception("Provided texture data is incorrect");

            return new Texture2D(Texture_LoadFromData(width, height, data, textureFormat));
        }
    }

    public enum TextureFormat
    {
        SingleColor = 1,
        RGB = 3,
        RGBA = 4,
    }
}
