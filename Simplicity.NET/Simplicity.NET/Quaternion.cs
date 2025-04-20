namespace Simplicity.NET;

public struct Quaternion
{
    public float W, X,Y, Z;

    public Quaternion(float w, float x, float y, float z)
    {
        this.W = w;
        this.X = x;
        this.Y = y;
        this.Z = z;
    }
}
