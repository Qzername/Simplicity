using Simplicity.NET.Graphics.Objects;
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

    public IntPtr GetPtr()
    {
        return _renderer;
    }

    public Color BackgroundColor
    {
        get => Renderer_getBackgroundColor(_renderer);
        set => Renderer_setBackgroundColor(_renderer, value);   
    }

    public Renderer(IntPtr renderer)
    {
        _renderer = renderer;
    }

    public void Render(GraphicsObject graphicsObject) => Renderer_render(_renderer, graphicsObject.GetPtr());
    public void Clear() => Renderer_clear(_renderer);
}
