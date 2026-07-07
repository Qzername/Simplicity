using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

Window window = new("Model loading example");

window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -10);
window.Graphics.Renderer.BackgroundColor = new Color(50, 75, 75);

GraphicsObject model = new GraphicsObject(Geometries.LoadModel(Directory.GetCurrentDirectory() + "/pillar.obj"));
model.Transform.EulerRotation = new(30, 0, 45);

window.OnFrame += (w) =>
{
    var renderer = window.Graphics.Renderer;

    renderer.Clear();
    renderer.Render(model);
};

window.Show();