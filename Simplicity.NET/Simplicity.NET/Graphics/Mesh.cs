using System.Runtime.InteropServices;
namespace Simplicity.NET.Graphics;

public class Mesh
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Mesh_create(
        [In] Vertex[] vertices, int vertexCount,
        [In] uint[] indices, int indexCount
    );

    IntPtr _mesh;

    internal IntPtr GetPtr()
    {
        return _mesh;
    }

    public Mesh(Vertex[] vertices, uint[] indices)
    {
        _mesh = Mesh_create(vertices, vertices.Length, indices, indices.Length);
    }
}
