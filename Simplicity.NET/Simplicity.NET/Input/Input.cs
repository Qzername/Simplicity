using System.Runtime.InteropServices;

namespace Simplicity.NET.InputProcessing;

public class Input
{
    [DllImport(LibConsts.LibPath)]
    static extern KeyStatus Input_getButton(IntPtr input, KeyCode key);
    [DllImport(LibConsts.LibPath)]
    static extern KeyStatus Input_getMouseButton(IntPtr input, MouseKeyCode key);
    [DllImport(LibConsts.LibPath)]
    static extern Vector2 Input_getCursorPosition(IntPtr input);
    [DllImport(LibConsts.LibPath)]
    static extern void Input_setMouseInputMode(IntPtr input, MouseInputMode value);

    IntPtr _input;

    public Vector2 MousePosition => Input_getCursorPosition(_input);

    internal Input(IntPtr input)
    {
        _input = input;
    }

    public KeyStatus GetButton(KeyCode key) => Input_getButton(_input, key);
    public KeyStatus GetMouseButton(MouseKeyCode key) => Input_getMouseButton(_input, key);
    public void SetMouseInputMode(MouseInputMode mode) => Input_setMouseInputMode(_input, mode);
}
