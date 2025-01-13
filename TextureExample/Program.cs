using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Texture example");

window.Camera.Transform.Position = new Vector3(0, 0, -1);

Rectangle rect = new(0,0, 0.2f, 0.2f);

Rectangle rect2 = new(-0.2f, -0.2f, 0.2f, 0.2f);
rect2.Color = new Color(50, 50, 255);

Rectangle rect3 = new(-0.2f, 0, 0.2f, 0.2f);

Texture2D texture = new(Directory.GetCurrentDirectory() + "/1.jpg");
Texture2D texture2 = new(Directory.GetCurrentDirectory() + "/2.jpg");

while (!window.ShouldClose())
{
    window.FrameCalculations();
    window.Clear(new Color(50, 75, 75));

    texture.SetActive();
    window.Draw(rect);

    texture2.SetActive();
    window.Draw(rect2);
    window.Draw(rect3);

    window.Render();
}
