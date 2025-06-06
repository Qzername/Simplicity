using Balls;
using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

float fps144 = 1f / 144f;

Window window = new Window("Balls");
window.Graphics.Camera.Transform.Position = new(0, 0, -90f);
window.Graphics.Camera.FOV = 70f;

var renderer = window.Graphics.Renderer;
renderer.BackgroundColor = new Color(100, 100, 100);

Simulation simulation = new Simulation();

GraphicsObject wheel = new GraphicsObject(Geometries.Wheel(64, Simulation.ConstrainRadius), new Vector3(0, 0, 0), new Color(0, 0, 0));

float timer = 0f;

window.SetOnFrame(() => {
    simulation.NextFrame(window.DeltaTime);

    renderer.Clear();
    foreach (var obj in simulation.Objects)
        obj.Render(renderer);

    renderer.Render(wheel);
    
    //manage fps cap (144fps)
    //for now library doesn't have built-in fps cap, will be added in future
    if (window.DeltaTime < fps144)
        Thread.Sleep(Convert.ToInt32((fps144 - window.DeltaTime) * 1000));

    timer += window.DeltaTime;

    //spawn 800 balls, 100 per second
    if (simulation.Objects.Count < 800)
    {
        if (timer < 0.01f)
            return;

        timer = 0f;

        simulation.AddBall(new Vector2(0, 40));
    }

});

window.Show();