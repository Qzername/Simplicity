using Simplicity.NET;
using Simplicity.NET.Graphics;
using Simplicity.NET.Graphics.Objects;
using Simplicity.NET.InputProcessing;

//for camera movement
bool firstMouse = true;
float lastX = 800 / 2;
float lastY = 600 / 2;

Window window = new Window("Objects showcase");

window.Graphics.Camera.Transform.Position = new Vector3(0, 0, -3);
window.Graphics.Renderer.BackgroundColor = new Color(50, 150, 150);

GraphicsObject rectangle = new GraphicsObject();
rectangle.Transform.Position = new Vector3(-1f, 0.5f,0);
rectangle.Geometry = Geometries.Rectangle(0.5f, 0.5f);

GraphicsObject cube = new GraphicsObject();
cube.Transform.EulerRotation = new Vector3(45, 0, 45);
cube.Color = new Color(50, 50, 255);
cube.Geometry = Geometries.Cube();

Vector3 mousePos = new Vector3();

window.SetOnFrame(() =>
{
    ProcessKeyboardInput();
    ProcessMouseInput();

    window.Graphics.Renderer.Clear();
    window.Graphics.Renderer.Render(rectangle);
    window.Graphics.Renderer.Render(cube);
});

window.Show();

// CAMERA MOVEMENT
void ProcessKeyboardInput()
{
    if (window.Input.GetButton(KeyCode.Escape) == KeyStatus.Pressed)
        window.Close();

    if (window.Input.GetButton(KeyCode.G) == KeyStatus.Pressed)
        window.Input.SetMouseInputMode(MouseInputMode.Disable);

    if (window.Input.GetButton(KeyCode.H) == KeyStatus.Pressed)
        window.Input.SetMouseInputMode(MouseInputMode.Enable);

    float cameraSpeed = 2.5f * window.DeltaTime;
    Vector3 cameraPos = new Vector3(0, 0, 0);

    if (window.Input.GetButton(KeyCode.W) == KeyStatus.Pressed)
        cameraPos += window.Graphics.Camera.Transform.Forward * cameraSpeed;
    if (window.Input.GetButton(KeyCode.S) == KeyStatus.Pressed)
        cameraPos -= window.Graphics.Camera.Transform.Forward * cameraSpeed;
    if (window.Input.GetButton(KeyCode.A) == KeyStatus.Pressed)
        cameraPos += window.Graphics.Camera.Transform.Right * cameraSpeed;
    if (window.Input.GetButton(KeyCode.D) == KeyStatus.Pressed)
        cameraPos -= window.Graphics.Camera.Transform.Right * cameraSpeed;

    if (window.Input.GetButton(KeyCode.Space) == KeyStatus.Pressed)
        cameraPos += window.Graphics.Camera.Transform.Up * cameraSpeed;
    if (window.Input.GetButton(KeyCode.LeftControl) == KeyStatus.Pressed)
        cameraPos -= window.Graphics.Camera.Transform.Up * cameraSpeed;

    window.Graphics.Camera.Transform.Position = window.Graphics.Camera.Transform.Position + cameraPos;
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