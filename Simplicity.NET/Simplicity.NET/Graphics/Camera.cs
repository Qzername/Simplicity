using Simplicity.NET.Graphics.Objects;
using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics
{
    public class Camera
    {
        [DllImport(LibConsts.LibPath)]
        static extern nint Camera_getTransform(nint camera);
        [DllImport(LibConsts.LibPath)]
        static extern float Camera_getFOV(nint camera);
        [DllImport(LibConsts.LibPath)]
        static extern void Camera_setFOV(nint camera, float FOV);

        nint _camera;

        Transform _transform;
        public Transform Transform => _transform;

        public float FOV
        {
            get => Camera_getFOV(_camera);
            set => Camera_setFOV(_camera, value);
        }

        internal Camera(nint camera)
        {
            _camera = camera;
            _transform = new Transform(Camera_getTransform(camera));
        }
    }
}
