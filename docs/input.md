---
sidebar_position: 5
---

# Input

To process input from the window use `window.Input` class.

Complete example of basic camera movement is in [this example](https://github.com/Qzername/Simplicity/tree/main/Simplicity.NET/Examples/ObjectsShowcase)

## Keyboard

To check if a keyboard button is pressed use `GetButton` method

```cs
var input = window.Input;

if (input.GetButton(KeyCode.Escape) == KeyStatus.Pressed)
    window.Close();
```

## Mouse

You can get mouse position by accessing `window.Input.MousePosition`

To get status of a mouse button you can use `GetMouseButton` which is simlar to `GetButton`

```cs
if (input.GetMouseButton(MouseKeyCode.Left) == KeyStatus.Pressed)
    input.SetMouseInputMode(MouseInputMode.Disable);
```

You can hide or show the cursor by using `SetMouseInputMode` method