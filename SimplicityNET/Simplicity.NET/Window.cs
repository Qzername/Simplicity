using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public class Window
    {
        // fields and properties
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Window_getCamera(IntPtr window);
        [DllImport(LibConsts.LibPath)]
        static extern float Window_getDeltaTime(IntPtr window);

        //constructors
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Window_create(string windowName);

        //functions
        [DllImport(LibConsts.LibPath)]
        static extern bool Window_shouldClose(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_frameCalculations(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_clear(IntPtr window, Color color);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_draw(IntPtr window, IntPtr drawable);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_render(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern int Window_getKey(IntPtr window, int key);

        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Window_getCursorPos(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_setMouseInputMode(IntPtr window, int value);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_close(IntPtr window);

        Camera _camera;
        IntPtr _window;

        public float DeltaTime => Window_getDeltaTime(_window);
        public Camera Camera => _camera;

        public Window(string windowName)
        {
            _window = Window_create(windowName);
            _camera = new Camera(Window_getCamera(_window));
        }

        public bool ShouldClose() => Window_shouldClose(_window);
        public void FrameCalculations() => Window_frameCalculations(_window);
        public void Clear(Color color) => Window_clear(_window, color);
        public void Draw(Drawable drawable) => Window_draw(_window, drawable.GetPtr());
        public void Render() => Window_render(_window);
        public int GetKey(int key) => Window_getKey(_window, key);
        public Vector3 GetCursorPos() => Window_getCursorPos(_window);
        public void SetMouseInputMode(int value) => Window_setMouseInputMode(_window, value);
        public void Close() => Window_close(_window);
    }
}
