using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class Geometry
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Geometry_create([In] IntPtr[] meshes, int meshCount);

    internal IntPtr _geometry;

    internal IntPtr GetPtr()
    {
        return _geometry;
    }

    internal Geometry(IntPtr geometry)
    {
        _geometry = geometry;
    }

    public Geometry(Mesh[] meshes)
    {
        var meshPtrs = new IntPtr[meshes.Length];

        for (int i = 0; i < meshes.Length; i++)
            meshPtrs[i] = meshes[i].GetPtr();

        _geometry = Geometry_create(meshPtrs, meshes.Length);
    }
}
