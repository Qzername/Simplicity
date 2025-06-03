using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;
using Simplicity.NET.InputProcessing;

//for camera movement
bool firstMouse = true;
float lastX = 800 / 2;
float lastY = 600 / 2;

Window window = new Window("Objects showcase");
var renderer = window.Graphics.Renderer;

window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -3);
renderer.BackgroundColor = new Color(50, 150, 150);

GraphicsObject rectangle = new GraphicsObject(Geometries.Rectangle(0.5f, 0.5f));
rectangle.Transform.Position = new Vector3(-1f, 0.5f,0);

GraphicsObject cube = new GraphicsObject(Geometries.Cube());
cube.Transform.EulerRotation = new Vector3(45, 0, 45);
cube.Color = new Color(50, 50, 255);

GraphicsObject wheel = new GraphicsObject(Geometries.Wheel(32, 0.5f));
wheel.Transform.Position = new Vector3(-2f, 1f, 0);

Vector3 mousePos = new Vector3();

window.SetOnFrame(() =>
{
    ProcessKeyboardInput();
    ProcessMouseInput();

    renderer.Clear();
    renderer.Render(rectangle);
    renderer.Render(cube);
    renderer.Render(wheel);
});

window.Show();

// CAMERA MOVEMENT
void ProcessKeyboardInput()
{
    var input = window.Input;
    var camera = window.Graphics.Camera;

    if (input.GetButton(KeyCode.Escape) == KeyStatus.Pressed)
        window.Close();

    if (input.GetButton(KeyCode.G) == KeyStatus.Pressed)
        input.SetMouseInputMode(MouseInputMode.Disable);

    if (input.GetButton(KeyCode.H) == KeyStatus.Pressed)
        input.SetMouseInputMode(MouseInputMode.Enable);

    float cameraSpeed = 2.5f * window.DeltaTime;
    Vector3 cameraPos = new Vector3(0, 0, 0);

    if (input.GetButton(KeyCode.W) == KeyStatus.Pressed)
        cameraPos += camera.Transform.Forward * cameraSpeed;
    if (input.GetButton(KeyCode.S) == KeyStatus.Pressed)
        cameraPos -= camera.Transform.Forward * cameraSpeed;
    if (input.GetButton(KeyCode.A) == KeyStatus.Pressed)
        cameraPos += camera.Transform.Right * cameraSpeed;
    if (input.GetButton(KeyCode.D) == KeyStatus.Pressed)
        cameraPos -= camera.Transform.Right * cameraSpeed;

    if (input.GetButton(KeyCode.Space) == KeyStatus.Pressed)
        cameraPos += camera.Transform.Up * cameraSpeed;
    if (input.GetButton(KeyCode.LeftControl) == KeyStatus.Pressed)
        cameraPos -= camera.Transform.Up * cameraSpeed;

    camera.Transform.Position = camera.Transform.Position + cameraPos;
}

void ProcessMouseInput()
{
    Vector2 vector3 = window.Input.MousePosition;

    float xpos = vector3.X;
    float ypos = vector3.Y;

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

    mousePos += new Vector3(-yoffset, xoffset,0);

    window.Graphics.Camera.Transform.EulerRotation = mousePos;
}