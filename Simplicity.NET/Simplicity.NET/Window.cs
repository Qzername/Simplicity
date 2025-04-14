using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void OnFrameDelegate();

    public class Window
    {
        // fields and properties
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Window_getCamera(IntPtr window);
        [DllImport(LibConsts.LibPath)]
        static extern float Window_getDeltaTime(IntPtr window);
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Window_getScene(IntPtr window);

        //constructors
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Window_create(string windowName);

        //functions
        [DllImport(LibConsts.LibPath)]
        static extern int Window_show(IntPtr window);
        [DllImport(LibConsts.LibPath)]
        static extern int Window_setOnFrame(IntPtr window, OnFrameDelegate callback);
        [DllImport(LibConsts.LibPath)]
        static extern int Window_getKey(IntPtr window, int key);

        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Window_getCursorPos(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_setMouseInputMode(IntPtr window, int value);

        [DllImport(LibConsts.LibPath)]
        static extern void Window_close(IntPtr window);

        Scene _scene;
        Camera _camera;
        IntPtr _window;

        public float DeltaTime => Window_getDeltaTime(_window);
        public Camera Camera => _camera;
        public Scene Scene => _scene;

        public Window(string windowName)
        {
            _window = Window_create(windowName);
            _camera = new Camera(Window_getCamera(_window));
            _scene = new Scene(Window_getScene(_window));
        }

        public void Show() => Window_show(_window);
        public void SetOnFrame(OnFrameDelegate onFrame) => Window_setOnFrame(_window, onFrame);
        /// <summary>
        /// Get the status of a specific key.
        /// </summary>
        public KeyStatus GetKey(KeyCode key) => (KeyStatus)Window_getKey(_window, Convert.ToInt32(key));
        /// <summary>
        /// Check the cursor position. Z is always 0.
        /// </summary>
        public Vector3 GetCursorPos() => Window_getCursorPos(_window);
        public void SetMouseInputMode(MouseInputMode mode) => Window_setMouseInputMode(_window, Convert.ToInt32(mode));
        public void Close() => Window_close(_window);
    }
}
