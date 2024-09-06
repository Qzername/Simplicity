using System.Runtime.InteropServices;

[DllImport("./libs/Simplicity.dll")]
static extern IntPtr createWindow();

[DllImport("./libs/Simplicity.dll")]
static extern void show(IntPtr window);

[DllImport("./libs/Simplicity.dll")]
static extern void addDrawable(IntPtr window, IntPtr drawable);

[DllImport("./libs/Simplicity.dll")]
static extern IntPtr createRectangle(float x, float y, float width, float height);

IntPtr window = createWindow();
IntPtr rectangle = createRectangle(0.5f, 0.5f, 0.5f, 0.5f);

addDrawable(window, rectangle);

show(window);