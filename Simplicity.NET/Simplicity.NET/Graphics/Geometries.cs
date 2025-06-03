using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public static class Geometries
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Geometries_cube();
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Geometries_rectangle(float width, float height);
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Geometries_loadModel(string path);
 
    public static Geometry Cube() => new Geometry(Geometries_cube());
    public static Geometry Rectangle(float width, float height) => new Geometry(Geometries_rectangle(width, height));   
    public static Geometry LoadModel(string path) => new Geometry(Geometries_loadModel(path));
}
