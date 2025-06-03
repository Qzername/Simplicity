using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

Window window = new("Texture example");

window.Graphics.Renderer.BackgroundColor = new Color(50, 75, 75);
window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -3);

Texture2D texture = Texture2D.LoadFromFile(Directory.GetCurrentDirectory() + "/1.jpg");

byte[] textureData = [
    255, 255, 255,
    0,   0,   0,
    255, 100, 100,
    100, 100, 100,
];
Texture2D texture2 = Texture2D.LoadFromData(2, 2, textureData, TextureFormat.RGB);

GraphicsObject rect = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
rect.Texture = texture2;
rect.Color = new Color(255, 0, 0);

GraphicsObject rect2 = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
rect2.Texture = texture;
rect2.Transform.Position = new Vector3(-0.5f, -0.5f, 0);
rect2.Color = new Color(50, 50, 255);

GraphicsObject rect3 = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
rect3.Transform.Position = new(-0.5f, 0, 0);
rect3.Texture = texture;


window.SetOnFrame(() =>
{
    window.Graphics.Renderer.Clear();
    window.Graphics.Renderer.Render(rect);
    window.Graphics.Renderer.Render(rect2);
    window.Graphics.Renderer.Render(rect3);
});

window.Show();