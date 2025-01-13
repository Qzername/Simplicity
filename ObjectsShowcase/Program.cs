using Simplicity.NET;
using Simplicity.NET.Objects;
using System.Collections.Generic;

//for camera movement
bool firstMouse = true;
float lastX = 800 / 2;
float lastY = 600 / 2;

Window window = new Window("Objects showcase");

window.Camera.Transform.Position = new Vector3(0, 0, -3);

Rectangle rect = new(-0.5f, 0.2f, 0.5f, 0.5f);

Cube cube = new(new Vector3(2f, 0, 4));
cube.Color = new Color(50, 50, 255);
cube.Transform.Rotation = new Vector3(45, 0, 45);

while (!window.ShouldClose())
{
    ProcessKeyboardInput();
    Vector3 cursorPos = window.GetCursorPos();
    ProcessMouseInput(cursorPos.X, cursorPos.Y);

    window.FrameCalculations();
    window.Clear(new Color(50, 150, 150));

    window.Draw(cube);
    window.Draw(rect);

    window.Render();
}

// CAMERA MOVEMENT
void ProcessKeyboardInput()
{
    if (window.GetKey(KeyCode.Escape) == KeyStatus.Pressed)
        window.Close();

    if (window.GetKey(KeyCode.G) == KeyStatus.Pressed)
        window.SetMouseInputMode(MouseInputMode.Disable);

    if (window.GetKey(KeyCode.H) == KeyStatus.Pressed)
        window.SetMouseInputMode(MouseInputMode.Enable);

    float cameraSpeed = 2.5f * window.DeltaTime;
    Vector3 cameraPos = new Vector3(0, 0, 0);

    if (window.GetKey(KeyCode.W) == KeyStatus.Pressed)
        cameraPos += window.Camera.Transform.Forward * cameraSpeed;
    if (window.GetKey(KeyCode.S) == KeyStatus.Pressed)
        cameraPos -= window.Camera.Transform.Forward * cameraSpeed;
    if (window.GetKey(KeyCode.A) == KeyStatus.Pressed)
        cameraPos += window.Camera.Transform.Right * cameraSpeed;
    if (window.GetKey(KeyCode.D) == KeyStatus.Pressed)
        cameraPos -= window.Camera.Transform.Right * cameraSpeed;

    if (window.GetKey(KeyCode.Space) == KeyStatus.Pressed)
        cameraPos += window.Camera.Transform.Up * cameraSpeed;
    if (window.GetKey(KeyCode.LeftShift) == KeyStatus.Pressed)
        cameraPos -= window.Camera.Transform.Up * cameraSpeed;

    window.Camera.Transform.Position = window.Camera.Transform.Position + cameraPos;
}

void ProcessMouseInput(float xpos, float ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = lastX - xpos;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    window.Camera.Transform.Rotation = window.Camera.Transform.Rotation + new Vector3(-yoffset, xoffset, 0);
}