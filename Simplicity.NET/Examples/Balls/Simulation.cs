using Simplicity.NET;

namespace Balls;

public class Simulation
{
    readonly Vector2 GravityAcceleration = new(0, -9.81F);
    public const float ConstrainRadius = 60f;

    public List<Ball> Objects = new List<Ball>();

    public Ball AddBall(Vector2 position)
    {
        var ball = new Ball(position);
        Objects.Add(ball);
        return ball;
    }

    public void NextFrame(float deltaTime)
    {
        HandleConstrains();
        HandleCollisions();
        UpdatePosition(deltaTime);
    }

    void HandleConstrains()
    {
        for (int i = 0; i < Objects.Count; i++)
        {
            var objA = Objects[i];
            var pos = objA.Position;

            var borderDist = Convert.ToSingle(CalculateDistance(new Vector3(0, 0, 0), new Vector3(objA.Position.X, objA.Position.Y, 0)));
            if (borderDist > ConstrainRadius - objA.Radius)
            {
                Vector2 n = new(
                    objA.Position.X / borderDist,
                    objA.Position.Y / borderDist
                );

                Objects[i].Position = n * (ConstrainRadius - objA.Radius);
            }
        }
    }

    void HandleCollisions()
    {
        for (int i = 0; i < Objects.Count; i++)
        {
            var objA = Objects[i];
            var pos = objA.Position;

            for (int j = i + 1; j < Objects.Count; j++)
            {
                var objB = Objects[j];

                float dist = Convert.ToSingle(CalculateDistance(new Vector3(pos.X, pos.Y, 0), new Vector3(objB.Position.X, objB.Position.Y, 0)));

                if (dist > objA.Radius + objB.Radius)
                    continue;

                Vector2 collisionAxis = pos - objB.Position;

                Vector2 n = new(collisionAxis.X / dist, collisionAxis.Y / dist);

                float delta = objA.Radius + objB.Radius - dist;

                pos += n * (objA.Radius / (objA.Radius + objB.Radius)) * delta;
                Objects[j].Position -= n * (objB.Radius / (objA.Radius + objB.Radius)) * delta;
            }

            Objects[i].Position = pos;
        }
    }

    void UpdatePosition(float delta)
    {
        //this simulation uses verlet integral for calculating position
        for (int i = 0; i < Objects.Count; i++)
        {
            var objA = Objects[i];
            var pos = objA.Position;

            var vel = objA.Velocity;
            Objects[i].PreviousPosition = pos;
            Objects[i].Position = pos + vel + GravityAcceleration * delta * delta;
        }
    }

    double CalculateDistance(Vector3 a, Vector3 b)
    {
        return Math.Sqrt(Math.Pow(a.X - b.X, 2) + Math.Pow(a.Y - b.Y, 2));
    }
}
