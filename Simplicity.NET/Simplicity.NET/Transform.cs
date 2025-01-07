using System.Runtime.InteropServices;

namespace Simplicity.NET
{
    /// <summary>
    /// Information about the position and rotation of an object.
    /// </summary>
    public class Transform
    {
        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Transform_getProperty(IntPtr transform, string name);

        [DllImport(LibConsts.LibPath)]
        static extern void Transform_setProperty(IntPtr transform, string name, Vector3 value);

        IntPtr _transform;

        internal Transform(IntPtr transform)
        {
            _transform = transform;
        }

        public Vector3 Position
        {
            get => Transform_getProperty(_transform, "position");
            set => Transform_setProperty(_transform, "position", value);
        }

        /// <summary>
        /// The rotation of the object in euler angles
        /// </summary>
        public Vector3 Rotation
        {
            get => Transform_getProperty(_transform, "rotation");
            set => Transform_setProperty(_transform, "rotation", value);
        }

        /// <summary>
        /// The direction the object is facing
        /// </summary>
        public Vector3 Forward => Transform_getProperty(_transform, "forward");

        /// <summary>
        /// The direction to the right where the object is facing
        /// </summary>
        public Vector3 Right => Transform_getProperty(_transform, "right");

        /// <summary>
        /// The direction upwards from the object
        /// </summary>
        public Vector3 Up => Transform_getProperty(_transform, "up");
    }
}
