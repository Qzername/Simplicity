using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public abstract class Drawable
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Drawable_getTransform(IntPtr drawable);
        [DllImport(LibConsts.LibPath)]
        static extern Color Drawable_getColor(IntPtr drawable);
        [DllImport(LibConsts.LibPath)]
        static extern void Drawable_setColor(IntPtr drawable, Color color);
        [DllImport(LibConsts.LibPath)]
        static extern void Drawable_setTexture(IntPtr drawable, IntPtr texture);

        IntPtr _drawable;
        internal IntPtr GetPtr()
        {
            return _drawable;
        }

        Transform _transform;
        public Transform Transform => _transform;

        public Color Color
        {
            get => Drawable_getColor(_drawable);
            set => Drawable_setColor(_drawable, value);
        }

        internal Drawable(IntPtr drawable)
        {
            _drawable = drawable;
            _transform = new Transform(Drawable_getTransform(drawable));
        }

        public void SetTexture(Texture2D texture) => Drawable_setTexture(_drawable, texture.GetPtr());
    }
}
