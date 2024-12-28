using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Simplicity.NET
{
    public class Transform
    {
        [DllImport(LibConsts.LibPath)]
        static extern Vector3 Transform_getProperty(IntPtr transform, string name);

        [DllImport(LibConsts.LibPath)]
        static extern void Transform_setProperty(IntPtr transform, string name, Vector3 value);

        IntPtr _transform;

        public Transform(IntPtr transform)
        {
            _transform = transform;
        }

        public Vector3 Position
        {
            get => Transform_getProperty(_transform, "position");
            set => Transform_setProperty(_transform, "position", value);
        }

        public Vector3 Rotation
        {
            get => Transform_getProperty(_transform, "rotation");
            set => Transform_setProperty(_transform, "rotation", value);
        }
    }
}
