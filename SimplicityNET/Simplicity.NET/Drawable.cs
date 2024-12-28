using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simplicity.NET
{
    public abstract class Drawable 
    {
        protected IntPtr drawable;
        internal IntPtr GetPtr()
        {
            return drawable;
        }
    }
}
