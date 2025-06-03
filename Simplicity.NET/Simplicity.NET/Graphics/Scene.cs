using Simplicity.NET.Graphics.Objects;
using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class Scene
{
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_instantiate(nint scene, nint drawable);
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_destroy(nint scene, nint drawable);

    [DllImport(LibConsts.LibPath)]
    static extern Color Scene_getBackgroundColor(nint scene);
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_setBackgroundColor(nint scene, Color color);

    nint _scene;

    public Color BackgroundColor
    {
        get => Scene_getBackgroundColor(_scene);
        set => Scene_setBackgroundColor(_scene, value);
    }

    public Scene(nint scene)
    {
        _scene = scene;
    }

    public void Instantiate(Drawable drawable) => Scene_instantiate(_scene, drawable.GetPtr());
    public void Destroy(Drawable drawable) => Scene_destroy(_scene, drawable.GetPtr());
}
