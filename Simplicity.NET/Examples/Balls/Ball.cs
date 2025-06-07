using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

namespace Balls;

public class Ball
{
    static Random rng = new Random();

    GraphicsObject graphicsObject;

    public Vector2 PreviousPosition;

    public Vector2 Position
    {
        get => (Vector2)graphicsObject.Transform.Position;
        set => graphicsObject.Transform.Position = value;
    }

    public Vector2 Velocity => Position - PreviousPosition;
    public Vector2 Acceleration;
    public float Radius;

    public Ball(Vector2 position, float radius = 1f)
    {
        Radius = radius + rng.NextSingle();

        graphicsObject = new GraphicsObject(
            Geometries.Wheel(16, Radius),
            new Vector3(position.X, position.Y, 0),
            new Color(rng.Next(0, 256), rng.Next(0, 256), rng.Next(0, 256))
        );

        Position = new Vector2(rng.NextSingle() * 80 - 40, position.Y);
        PreviousPosition = Position;
    }

    public void Render(Renderer renderer)
    {
        renderer.Render(graphicsObject);
    }
}
