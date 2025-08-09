---
sidebar_position: 7
---

# Geometries

The `Geometries` class contains default geometries as well as tool intended for custom model loading.

## Objects

You can see the all default geometries in [this example](https://github.com/Qzername/Simplicity/tree/main/Simplicity.NET/Examples/ObjectsShowcase).

### Rectangle

`Geometries.Rectangle(float width, float height)`

```cs
GraphicsObject rect = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
```

### Cube

`Geometries.Cube()`

```cs
GraphicsObject cube = new GraphicsObject(Geometries.Cube());
```

### Wheel

`Geometries.Wheel(uint segments, float radius)`

Segments define the number of triangles that the wheel will contain.

```cs 
GraphicsObject wheel = new GraphicsObject(Geometries.Wheel(32, 0.5f));
```

## Model loading

You can see an example of model loading [here](https://github.com/Qzername/Simplicity/tree/main/Simplicity.NET/Examples/ModelLoadingExample).

To load a model use the `Geometries.LoadModel` method.

```cs
GraphicsObject model = new GraphicsObject(Geometries.LoadModel(Directory.GetCurrentDirectory() + "/pillar.obj"));
```

:::info
The path to the texture must be absolute. Relative paths, such as `./path/to/model.obj`, are not supported.
:::