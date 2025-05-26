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

### 0.2v Roadmap (Planned features)
- [x] Scenes 
- [x] Add Scale
- [x] Move rotation to quaternions
- [x] Move texture loading into a separate tool
- [x] Add default shaders into the library
- [x] Alpha channel (transparency)
- [ ] Lighting
- [ ] Viewports
- [ ] Add easier way to add custom shaders
- [ ] Drawing tool for simple shapes such as lines, circles, rectangles
- [ ] Reorganize solution so that it will be easier to compile the project
- [ ] Improvements specified in comments that contain "TODO"
- [ ] Improve model loading

### 0.3v Roadmap

For now, I don't have a general plan on how library should be structured, and creating the structure of the whole library will be a focus for 0.3v
