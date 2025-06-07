# Simplicity

Simplicity is a graphics library for C# designed to be as straightforward as possible.
The library minimizes the lines of code required to draw 2D/3D objects on the screen.

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

## Roadmap

### 0.4v 

- [ ] Viewports
- [ ] Unit tests
- [ ] Brushes for canvas
- [ ] Automatic link files generation
- [ ] Cmake and configure C# project for easier compilation
- [ ] Easier way to add custom shaders
- [ ] Space-screen position conversion
- [ ] In runtime window title control
- [ ] Window position control
- [ ] Ability to change window icon

### 0.5v

- [ ] Lighting

