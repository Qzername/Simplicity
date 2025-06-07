using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics;

public class Canvas
{
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Canvas_create(IntPtr renderer);
    [DllImport(LibConsts.LibPath)]
    static extern void Canvas_drawWheel(IntPtr canvas, Vector3 center, float radius);
    [DllImport(LibConsts.LibPath)]
    static extern void Canvas_drawRectangle(IntPtr canvas, Vector3 topLeft, Vector3 bottomRight);
    [DllImport(LibConsts.LibPath)]
    static extern void Canvas_drawCube(IntPtr canvas, Vector3 center);

    IntPtr _canvas;

    public Canvas(Renderer renderer)
    {
        _canvas = Canvas_create(renderer.GetPtr());
    }

    public void DrawWheel(Vector3 center, float radius)
    {
        Canvas_drawWheel(_canvas, center, radius);
    }

    public void DrawRectangle(Vector3 topLeft, Vector3 bottomRight)
    {
        Canvas_drawRectangle(_canvas, topLeft, bottomRight);
    }

    public void DrawCube(Vector3 center)
    {
        Canvas_drawCube(_canvas, center);
    }
}
