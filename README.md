# Simplicity

Simplicity is a graphics library for C# designed to simplify drawing 2D and 3D objects on the screen while maintaining excellent modularity.

The core is written in C++ in a way that makes it easy to add support for languages other than C#. In the (far) future, I plan to add support for more languages, such as Python.

> [!WARNING]
> This project is still a work in progress. Expect frequent changes between versions, bugs, and missing features.

A NuGet package for this project has not been created yet. Please see the wiki for more information on how to install the library.

### Example code:

```cs
using Simplicity.NET;
using Simplicity.NET.Graphics.Objects;
using Simplicity.NET.Graphics;

Window window = new Window("Objects showcase");
var renderer = window.Graphics.Renderer;

window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -3);
renderer.BackgroundColor = new Color(50, 150, 150);

GraphicsObject cube = new GraphicsObject(Geometries.Cube());
cube.Transform.EulerRotation = new Vector3(45, 0, 45);
cube.Color = new Color(50, 50, 255);

window.SetOnFrame(() =>
{
    renderer.Clear();
    renderer.Render(cube);
});

window.Show();
```

**Official documentation is available [here](https://qzername.github.io/Simplicity/)**

## Roadmap

### 0.4v 

- [x] Cmake configuration
- [ ] Reorganize project
- [ ] Automatic link files generation
- [ ] Unit tests
- [ ] Viewports
- [ ] Brushes for canvas
- [ ] In code model creation
- [ ] Easier way to add custom shaders
- [ ] Space-screen position conversion
- [ ] In-runtime window title control
- [ ] Ability to change window icon
- [ ] Window position control

### 0.5v

- [ ] Lighting
*and more... (TBD)*