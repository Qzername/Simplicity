﻿namespace Simplicity.NET;

public struct Vector2
{
    public float X;
    public float Y;

    public Vector2(float x, float y)
    {
        X = x;
        Y = y;
    }

    public static explicit operator Vector2(Vector3 value)
    {
        return new Vector2(value.X, value.Y);
    }

    public static Vector2 operator +(Vector2 a, Vector2 b)
    {
        return new Vector2(a.X + b.X, a.Y + b.Y);
    }

    public static Vector2 operator -(Vector2 a, Vector2 b)
    {
        return new Vector2(a.X - b.X, a.Y - b.Y);
    }

    public static Vector2 operator *(Vector2 a, float b)
    {
        return new Vector2(a.X * b, a.Y * b);
    }

    public override string ToString()
    {
        return $"X: {X}, Y: {Y}";
    }
}
