using System.Runtime.InteropServices;
using Simplicity.NET.Graphics;
using Simplicity.NET.InputProcessing;

namespace Simplicity.NET;

[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
public delegate void OnFrameDelegate();

public class Window
{
    // fields and properties
    [DllImport(LibConsts.LibPath)]
    static extern float Window_getDeltaTime(IntPtr window);
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Window_getInput(IntPtr window);
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Window_getGraphics(IntPtr window);

    //constructors
    [DllImport(LibConsts.LibPath)]
    static extern IntPtr Window_create(string windowName);

    //functions
    [DllImport(LibConsts.LibPath)]
    static extern int Window_show(IntPtr window);
    [DllImport(LibConsts.LibPath)]
    static extern int Window_setOnFrame(IntPtr window, OnFrameDelegate callback);
    [DllImport(LibConsts.LibPath)]
    static extern void Window_close(IntPtr window);

    IntPtr _window;

    public float DeltaTime => Window_getDeltaTime(_window);

    Input _input;
    public Input Input => _input;
    
    GraphicsSystem _graphics;
    public GraphicsSystem Graphics => _graphics;

    public Window(string windowName)
    {
        _window = Window_create(windowName);
        _input = new Input(Window_getInput(_window));
        _graphics = new GraphicsSystem(Window_getGraphics(_window));
    }

    public void Show() => Window_show(_window);
    public void SetOnFrame(OnFrameDelegate onFrame) => Window_setOnFrame(_window, onFrame);
    public void Close() => Window_close(_window);
}
