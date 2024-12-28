using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Simplicity.NET
{
    public class Camera
    {
        [DllImport(LibConsts.LibPath)]
        static extern IntPtr Camera_getTransform(IntPtr camera);
        [DllImport(LibConsts.LibPath)]
        static extern float Camera_getFOV(IntPtr camera);
        [DllImport(LibConsts.LibPath)]
        static extern void Camera_setFOV(IntPtr camera, float FOV);
        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Camera_getDirections(IntPtr camera, string directionName);

        IntPtr _camera;

        Transform _transform;
        public Transform Transform => _transform;

        public float FOV
        {
            get => Camera_getFOV(_camera);
            set => Camera_setFOV(_camera, value);
        }

        public Vector3 CameraUp => Camera_getDirections(_camera, "cameraUp");
        public Vector3 CameraFront => Camera_getDirections(_camera, "cameraFront");
        public Vector3 CameraRight => Camera_getDirections(_camera, "cameraRight");

        internal Camera(IntPtr camera)
        {
            _camera = camera;
            _transform = new Transform(Camera_getTransform(camera));
        }
    }
}
