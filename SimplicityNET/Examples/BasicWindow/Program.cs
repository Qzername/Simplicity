using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Window and rectangle");
Rectangle rect = new(0.0f, 0.0f, 0.5f, 0.5f);

while (!window.ShouldClose())
{
    window.FrameCalculations();
    window.Clear(new Color(0.2f, 0.3f, 0.3f));
    window.Render();
}