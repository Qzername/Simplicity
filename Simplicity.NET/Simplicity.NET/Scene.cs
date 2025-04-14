using System.Runtime.InteropServices;

namespace Simplicity.NET;

public class Scene
{
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_instantiate(IntPtr scene, IntPtr drawable);
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_destroy(IntPtr scene, IntPtr drawable);

    [DllImport(LibConsts.LibPath)]
    static extern Color Scene_getBackgroundColor(IntPtr scene);
    [DllImport(LibConsts.LibPath)]
    static extern void Scene_setBackgroundColor(IntPtr scene, Color color);

    IntPtr _scene;

    public Color BackgroundColor
    {
        get => Scene_getBackgroundColor(_scene);
        set => Scene_setBackgroundColor(_scene, value);
    }

    public Scene(IntPtr scene)
    {
        _scene = scene;
    }

    public void Instantiate(Drawable drawable) => Scene_instantiate(_scene, drawable.GetPtr());
    public void Destroy(Drawable drawable) => Scene_destroy(_scene, drawable.GetPtr()); 
}
