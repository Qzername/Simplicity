---
sidebar_position: 6
---

# Textures

Example of texture loading is available [here](https://github.com/Qzername/Simplicity/tree/main/Simplicity.NET/Examples/TextureExample)

To apply a texture to an objects, first, load it using `Texture2D.LoadFromFile` method:

```cs 
Texture2D texture = Texture2D.LoadFromFile("C:\\[...]\\your-project\\img.png");
```

:::info
The path to the texture must be absolute. Relative paths, such as `./path/to/texture.jpg`, are not supported.
:::
Currently, only JPG files have been tested. If you encounter loading issues, try using a different format.

Next, assign the texture to the desired graphics object:

```cs
GraphicsObject rect = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
rect.Texture = texture;
```