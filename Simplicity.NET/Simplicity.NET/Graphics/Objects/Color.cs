namespace Simplicity.NET.Graphics.Objects
{
    public struct Color
    {
        public float R;
        public float G;
        public float B;
        public float W;

        public Color(float r, float g, float b)
        {
            R = r;
            G = g;
            B = b;
            W = 255;
        }

        public Color(float r, float g, float b, float alpha)
        {
            R = r;
            G = g;
            B = b;
            W = alpha;
        }
    }
}
