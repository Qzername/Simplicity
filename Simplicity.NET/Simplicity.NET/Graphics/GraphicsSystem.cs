using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class GraphicsSystem
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Graphics_getScene(IntPtr graphics);
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Graphics_getRenderer(IntPtr graphics);

    IntPtr _graphics;

    Scene _scene;
    public Scene Scene => _scene;

    Renderer _renderer;
    public Renderer Renderer => _renderer;

    internal GraphicsSystem(IntPtr graphics) 
    {
        _graphics = graphics;
        _scene = new Scene(Graphics_getScene(_graphics));   
        _renderer = new Renderer(Graphics_getRenderer(_graphics));
    }
}
