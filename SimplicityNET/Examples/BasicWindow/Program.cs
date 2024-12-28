using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Window and rectangle");
Rectangle rect = new(0.0f, 0.0f, 1f, 1f);

window.SetCameraPosition(new Vector3(0, 0, -3));
window.SetCameraRotation(new Vector3(0, 0, 90));

while (!window.ShouldClose())
{
    window.FrameCalculations();
    window.Clear(new Color(0.2f, 0.3f, 0.3f));
    window.Draw(rect);
    window.Render();
}