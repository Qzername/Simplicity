using Simplicity.NET.Graphics.Objects;
using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class Scene
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Scene_create();

    [DllImport(LibConsts.LibPath)]
    static extern void Scene_instantiate(IntPtr scene, IntPtr graphicsObject);
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_destroy(IntPtr scene, IntPtr graphicsObject);

    [DllImport(LibConsts.LibPath)]
    static extern void Scene_render(IntPtr scene, IntPtr renderer);

    IntPtr _scene;

    public Scene()
    {
        _scene = Scene_create();
    }

    public void Instantiate(GraphicsObject graphicsObject) => Scene_instantiate(_scene, graphicsObject.GetPtr());
    public void Destroy(GraphicsObject graphicsObject) => Scene_destroy(_scene, graphicsObject.GetPtr());
    public void Render(Renderer renderer) => Scene_render(_scene, renderer.GetPtr());
}
