using System.Runtime.InteropServices;

namespace Simplicity.NET.Graphics.Objects
{
    /// <summary>
    /// Information about the position and rotation of an object.
    /// </summary>
    public class Transform
    {
        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Transform_getProperty(nint transform, string name);

        [DllImport(LibConsts.LibPath)]
        static extern void Transform_setProperty(nint transform, string name, Vector3 value);

        [DllImport(LibConsts.LibPath)]
        static extern Quaternion Transform_getQuaternion(nint transform);

        [DllImport(LibConsts.LibPath)]
        static extern void Transform_setQuaternion(nint transform, Quaternion value);

        nint _transform;

        internal Transform(nint transform)
        {
            _transform = transform;
        }

        public Vector3 Position
        {
            get => Transform_getProperty(_transform, "position");
            set => Transform_setProperty(_transform, "position", value);
        }

        #region Rotation
        /// <summary>
        /// The rotation of the object in euler angles
        /// </summary>
        public Vector3 EulerRotation
        {
            get => Transform_getProperty(_transform, "eulerRotation");
            set => Transform_setProperty(_transform, "eulerRotation", value);
        }

        public Quaternion Rotation
        {
            get => Transform_getQuaternion(_transform);
            set => Transform_setQuaternion(_transform, value);
        }
        #endregion

        public Vector3 Scale
        {
            get => Transform_getProperty(_transform, "scale");
            set => Transform_setProperty(_transform, "scale", value);
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
