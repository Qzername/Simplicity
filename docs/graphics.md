---
sidebar_position: 4
---

# Graphics

## Rendering objects the on screen

You can render objects on the screen by directly using the window's Renderer (`Window.Graphics.Renderer`).

You can use also built-in tools to make object management easier. These tools are:
- [Canvas](/canvas.md)
- [Scene](/scene.md)

This page describes the first of the mentioned approach to render object, that is, by directly using `Renderer`.

### Creating Graphics Object

To render objects on the screen create a `GraphicsObject`.

`GraphicsObject` contains basic information about object, such as its geometry, color, texture, or position contained in transform.

The default color of object is white, and if we don't set the position, the object will be placed at the position 0,0,0.

To create a new GraphicsObject, create a new geometry, or use one of  the default objects contained in `Geometries` class. More about default geometries is [here](/geometries.md).

```cs
GraphicsObject cube = new GraphicsObject(Geometries.Cube());
cube.Transform.Position = new Vector3(0, 0, 4);
cube.Transform.EulerRotation = new Vector3(45, 0, 45);
cube.Color = new Color(50, 50, 255);
```

### Rendering Graphics Object

Before rendering our object, We want to clear screen using `Clear` method. Now, to render previously created graphics object simply use `Render` method. 

```cs
window.SetOnFrame(() =>
{
    window.Graphics.Renderer.Clear();
    window.Graphics.Renderer.Render(cube);
});
```

You can switch the background color by modifying `window.Graphics.Renderer.BackgroundColor` property.

:::tip

You can save `window.Graphics.Renderer` to a seperate variable to avoid redundancy.

:::

Here is complete example code:

```cs
using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;

Window window = new Window("Objects showcase");
var renderer = window.Graphics.Renderer;

renderer.BackgroundColor = new Color(50, 150, 150);

GraphicsObject cube = new GraphicsObject(Geometries.Cube());
cube.Transform.Position = new Vector3(0, 0, 4);
cube.Transform.EulerRotation = new Vector3(45, 0, 45);
cube.Color = new Color(50, 50, 255);

window.SetOnFrame(() =>
{
    renderer.Clear();
    renderer.Render(cube);
});

window.Show();
```

![Cube](/img/basicCube.png)

## Camera

To change the camera positon, rotation or FOV use `window.Graphics.Camera`.

```cs
var camera = window.Graphics.Camera;

//the default FOV is 45;
camera.FOV = 50f; 
camera.Transform.Position = new Vector3(0,0,-3);
camera.Transform.EulerRotation = new Vector3(0,45,0);
```