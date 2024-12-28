using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public class Window
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr createWindow(string windowName);

        [DllImport(LibConsts.LibPath)]
        static extern bool shouldClose(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void frameCalculations(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void clear(IntPtr window, Color color);

        [DllImport(LibConsts.LibPath)]
        static extern void draw(IntPtr window, IntPtr drawable);

        [DllImport(LibConsts.LibPath)]
        static extern void render(IntPtr window);

        //camera
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr getCamera(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void setCameraPosition(IntPtr camera, Vector3 position);

        [DllImport(LibConsts.LibPath)]
        static extern void setCameraRotation(IntPtr camera, Vector3 rotation);

        IntPtr window, camera;

        public Window(string windowName)
        {
            window = createWindow(windowName);
            camera = getCamera(window);
        }

        public bool ShouldClose() => shouldClose(window);
        public void FrameCalculations() => frameCalculations(window);
        public void Clear(Color color) => clear(window, color);
        public void Draw(Drawable drawable) => draw(window, drawable.GetPtr());
        public void Render() => render(window);

        //camera
        public void SetCameraPosition(Vector3 position) => setCameraPosition(camera, position);
        public void SetCameraRotation(Vector3 rotation) => setCameraRotation(camera, rotation);
    }
}
