using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Texture example");
window.Scene.BackgroundColor = new Color(50, 75, 75);
window.Camera.Transform.Position = new Vector3(0, 0, -1);

Texture2D texture = Texture2D.LoadFromFile(Directory.GetCurrentDirectory() + "/1.jpg");

byte[] textureData = [
    255, 255, 255,
    0,   0,   0,
    255, 100, 100,
    100, 100, 100,
];
Texture2D texture2 = Texture2D.LoadFromData(2, 2, textureData, TextureFormat.RGB);

Rectangle rect = new(0,0, 0.2f, 0.2f);
rect.SetTexture(texture);

Rectangle rect2 = new(-0.2f, -0.2f, 0.2f, 0.2f);
rect2.SetTexture(texture2);
rect2.Color = new Color(50, 50, 255);

Rectangle rect3 = new(-0.2f, 0, 0.2f, 0.2f);
rect3.SetTexture(texture2);

window.Scene.Instantiate(rect);
window.Scene.Instantiate(rect2);
window.Scene.Instantiate(rect3);

window.Show();