using System.Drawing;
using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class Renderer
{
    [DllImport(LibConsts.LibPath)]
    static extern Color Renderer_getBackgroundColor(IntPtr renderer);
    [DllImport(LibConsts.LibPath)]
    static extern void Renderer_setBackgroundColor(IntPtr renderer, Color color);

    [DllImport(LibConsts.LibPath)]
    static extern void Renderer_render(IntPtr renderer, IntPtr graphicsObject);
    [DllImport(LibConsts.LibPath)]
    static extern void Renderer_clear(IntPtr renderer);

    IntPtr _renderer;

    public Renderer(IntPtr renderer)
    {
        _renderer = renderer;
    }
}
