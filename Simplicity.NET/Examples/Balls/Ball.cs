using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

namespace Balls;

public class Ball
{
    static Random rng = new Random();

    GraphicsObject graphicsObject;

    public Vector2 PreviousPosition;

    /*
     * the reason behind this value is that getting 
     * every time position from C++ side of library is costly 
     * 
     * so we set position to graphics object only when necessary
     * 
     * I will optimize this in the future.
     */
    bool isDirty = false;
    Vector2 _tempPosition;
    public Vector2 Position
    {
        get => _tempPosition;
        set
        {
            _tempPosition = value;
            isDirty = true;
        }
    }

    public Vector2 Velocity => Position - PreviousPosition;
    public Vector2 Acceleration;
    public float Radius;

    public Ball(Vector2 position, float radius = 1f)
    {
        Position = new Vector2(rng.NextSingle() * 80 - 40, position.Y);
        PreviousPosition = Position;

        Radius = radius + rng.NextSingle();

        graphicsObject = new GraphicsObject(
            Geometries.Wheel(16, Radius),
            new Vector3(Position.X, Position.Y, 0),
            new Color(rng.Next(0, 256), rng.Next(0, 256), rng.Next(0, 256))
        );
    }

    public void Render(Renderer renderer)
    {
        if (isDirty)
        {
            graphicsObject.Transform.Position = new Vector3(Position.X, Position.Y, 0);
            isDirty = false;
        }
        renderer.Render(graphicsObject);
    }
}
