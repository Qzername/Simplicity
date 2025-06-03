using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class GraphicsSystem
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Graphics_getCamera(IntPtr graphics);
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Graphics_getRenderer(IntPtr graphics);

    IntPtr _graphics;

    Camera _camera;
    public Camera Camera => _camera;

    Renderer _renderer;
    public Renderer Renderer => _renderer;

    internal GraphicsSystem(IntPtr graphics) 
    {
        _graphics = graphics;

        _camera = new Camera(Graphics_getCamera(_graphics));
        _renderer = new Renderer(Graphics_getRenderer(_graphics));
    }
}
