---
sidebar_position: 8
---

# Canvas

Canvas is a tool for quickly rendering objects on screen on the current frame.

Firstly we create it providing renderer as a parameter.

```cs
Window window = new Window("Canvas example");
Canvas canvas = new Canvas(window.Graphics.Renderer);
```

Now, we can use it to some of the default geometries.

```cs
window.SetOnFrame(() =>
{
    renderer.Clear();
    canvas.DrawRectangle(new Vector2(0, 0), new Vector2(800, 600));
});
```