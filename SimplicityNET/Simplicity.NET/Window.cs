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

        IntPtr window;

        public Window(string windowName)
        {
            window = createWindow(windowName);
        }

        public bool ShouldClose() => shouldClose(window);
        public void FrameCalculations() => frameCalculations(window);
        public void Clear(Color color) => clear(window, color);
        public void Draw(Drawable drawable) => draw(window, drawable.GetPtr());
        public void Render() => render(window);
    }
}
