using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Model loading example");

window.Camera.Transform.Position = new Vector3(0, 0, -10);
window.Scene.BackgroundColor = new Color(50, 75, 75);

Model model = new Model(Directory.GetCurrentDirectory() + "/pillar.obj");
model.Transform.Rotation = new(30, 0, 45);

window.Show();