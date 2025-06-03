using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics.Objects;

public class GraphicsObject
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr GraphicsObject_create();

    [DllImport(LibConsts.LibPath)]
    static extern Color GraphicsObject_getColor(IntPtr graphics);
    [DllImport(LibConsts.LibPath)]
    static extern void GraphicsObject_setColor(IntPtr graphics, Color color);

    [DllImport(LibConsts.LibPath)]
    static extern IntPtr GraphicsObject_getTransform(IntPtr graphics);

    [DllImport(LibConsts.LibPath)]
    static extern IntPtr GraphicsObject_getTexture(IntPtr graphics);
    [DllImport(LibConsts.LibPath)]
    static extern void GraphicsObject_setTexture(IntPtr graphics, IntPtr texture);

    [DllImport(LibConsts.LibPath)]
    static extern IntPtr GraphicsObject_getGeometry(IntPtr graphics);
    [DllImport(LibConsts.LibPath)]
    static extern void GraphicsObject_setGeometry(IntPtr graphics, IntPtr geometry);

    IntPtr _graphicsObject;
    internal IntPtr GetPtr() => _graphicsObject;

    Transform _transform;
    public Transform Transform => _transform;

    public Color Color
    {
        get => GraphicsObject_getColor(_graphicsObject);
        set => GraphicsObject_setColor(_graphicsObject, value);
    }

    public Texture2D Texture
    {
        get=> new Texture2D(GraphicsObject_getTexture(_graphicsObject));
        set=> GraphicsObject_setTexture(_graphicsObject, value.GetPtr());
    }

    public Geometry Geometry
    {
        get => new Geometry(GraphicsObject_getGeometry(_graphicsObject));
        set => GraphicsObject_setGeometry(_graphicsObject, value.GetPtr());
    }

    public GraphicsObject(Geometry geometry)
    {
        ConfigureObject();

        Geometry = geometry;
    }

    public GraphicsObject(Geometry geometry, Vector3 position)
    {
        ConfigureObject();

        Transform.Position = position;
        Geometry = geometry;
    }

    public GraphicsObject(Geometry geometry, Vector3 position, Color color)
    {
        ConfigureObject();

        Transform.Position = position;
        Geometry = geometry;
        Color = color;
    }

    void ConfigureObject()
    {
        _graphicsObject = GraphicsObject_create();
        _transform = new Transform(GraphicsObject_getTransform(_graphicsObject));
    }
}
