using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    public class Window
    {
        [DllImport("./libs/Simplicity.dll")]
        static extern IntPtr createWindow();

        [DllImport("./libs/Simplicity.dll")]
        static extern void show(IntPtr window);

        [DllImport("./libs/Simplicity.dll")]
        static extern void addDrawable(IntPtr window, IntPtr drawable);

        IntPtr window;

        public Window()
        {
            window = createWindow();
        }

        public void Show() => show(window);
        public void AddDrawable(Drawable drawable) => addDrawable(window, drawable.GetPtr());
    }
}
