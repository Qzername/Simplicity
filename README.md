# Simplicity

Simplicity is a graphics library for C# designed to be as straightforward as possible.
The library minimizes the lines of code required to draw 2D/3D objects on the screen.

> [!WARNING]
> This project is still a work in progress. Expect frequent changes between versions, bugs, and missing features.

This project does not have a NuGet package yet. Please see the wiki for more information on how to install the library.

### Example code:

```cs
using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new("Window title");

Cube cube = new(1,1,1);

while(!window.ShouldClose())
{
  window.FrameCalculations();
  window.Clear(new(100,50,50));
  window.Draw(cube);
  window.Render();
}
```

### Roadmap (Planned features)
- More ready-to-use objects in both 2D and 3D
- Scenes 
- Lighting
- Viewports

### Planned improvements
- Model and texture loading
- Rotation
- Optimalization
- Better input system
