---
sidebar_position: 9
---

# Scene

Scene is a tool for rendering objects that will be more than couple frames on the screen.

```cs
Scene scene = new();
```

You can add graphics objects to the screen using `Instantiate` method. 

If you want to remove object later on, use `Destroy` method.

```cs
GraphicsObject rectangle = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));

scene.Instantiate(rectangle);
scene.Destroy(rectangle);
```

Once added object, will be always rendered on the screen until you obviously destroy it.

```cs
window.SetOnFrame(() =>
{
    renderer.Clear();
    scene.Render(renderer);
});
```