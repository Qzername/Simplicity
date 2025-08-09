---
sidebar_position: 3
---

# Window

## Basic Window

If you're looking for ready-to-use code, check out the [Basic Window example](https://github.com/Qzername/Simplicity/tree/main/Simplicity.NET/Examples/BasicWindow).

You can create a window by first creating an instance of the Window class:

`Window window = new("Basic window");`

`"Basic window"` is the title of the window.

To display the window, call `window.Show();` method.

```cs 
using Simplicity.NET;

Window window = new Window("Basic window");

window.Show();
```

![Basic window](/img/examples/BasicWindow.png)

:::info
If you choose the Console App project template, you can hide console by going to project properties and changing the output type to Windows Application.
:::

You can later on close the window by using `Close` method.

## Frames

To receive a callback every time a frame is rendered, you can use `SetOnFrame` method.

```cs
window.SetOnFrame(() =>
{
    Debug.WriteLine("new frame");
});
```

You can also access the interval in seconds from the last frame to the current one by accessing value `DeltaTime`

```cs
window.SetOnFrame(() =>
{
    Debug.WriteLine("FPS: " + (1/window.DeltaTime).ToString());
});
```