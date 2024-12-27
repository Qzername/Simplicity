using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public class Window
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr createWindow();

        [DllImport(LibConsts.LibPath)]
        static extern bool shouldClose(IntPtr window);

        [DllImport(LibConsts.LibPath)]
        static extern void render(IntPtr window);

        IntPtr window;

        public Window()
        {
            window = createWindow();
        }

        public bool ShouldClose() => shouldClose(window);
        public void Render() => render(window);
    }
}
