using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

Window window = new("Model loading example");

window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -10);
window.Graphics.Renderer.BackgroundColor = new Color(50, 75, 75);

GraphicsObject model = new GraphicsObject();
model.Geometry = Geometries.LoadModel(Directory.GetCurrentDirectory() + "/pillar.obj");
model.Transform.EulerRotation = new(30, 0, 45);

window.SetOnFrame(() =>
{
    window.Graphics.Renderer.Clear();
    window.Graphics.Renderer.Render(model);
});

window.Show();