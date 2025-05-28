# Simplicity

Simplicity is a graphics library for C# designed to be as straightforward as possible.
The library minimizes the lines of code required to draw 2D/3D objects on the screen.

> [!WARNING]
> This project is still a work in progress. Expect frequent changes between versions, bugs, and missing features.

A NuGet package for this project has not been created yet. Please see the wiki for more information on how to install the library.

### Example code:

```cs
using Simplicity.NET;
using Simplicity.NET.Objects;

Window window = new Window("Objects showcase");

window.Camera.Transform.Position = new Vector3(0, 0, -3);
window.Scene.BackgroundColor = new Color(50, 150, 150);

Cube cube = new(new Vector3(2f, 0, 4));
cube.Color = new Color(50, 50, 255);
cube.Transform.EulerRotation = new Vector3(45, 0, 45);

window.Scene.Instantiate(cube);

window.Show();
```

## Roadmap

### 0.3v 

- [ ] New structure of drawing on screen 
- [ ] New structure for window management
- [ ] Drawing tool for simple shapes such as lines, circles, rectangles

### 0.4v 

- [ ] Lighting
- [ ] Viewports
- [ ] Add easier way to add custom shaders
- [ ] Add Cmake and configure C# project for easier compilation
