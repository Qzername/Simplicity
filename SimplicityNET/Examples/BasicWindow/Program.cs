using Simplicity.NET;
using Simplicity.NET.Objects;

bool firstMouse = true;
float lastX = 800.0f / 2.0f;
float lastY = 600.0f / 2.0f;

Window window = new("Basic window with basic stuff");

window.Camera.Transform.Position = new Vector3(0, 0, 2);
//just noticed that camera rotation is in angles, where cube and rectangle are in range from 0.0f to 1.0f
window.Camera.Transform.Rotation = new Vector3(0, 0f, -90);

Rectangle rect = new(0.2f, 0.2f, 0.5f, 0.5f);
rect.Transform.Rotation = new Vector3(0.5f, 0.5f, 0.0f);

Rectangle rect2 = new(-0.5f, -0.5f, 0.1f, 0.1f);
rect2.Color = new Color(0.2f, 0.2f, 1);

Cube cube = new(new Vector3(0.2f, 0, -1));
cube.Transform.Rotation = new Vector3(0.5f, 0.5f, 0.5f);

cube.Color = new Color(0.2f, 0.2f, 1);

Console.WriteLine(Directory.GetCurrentDirectory());

Texture2D texture = new(Directory.GetCurrentDirectory() + "/1.jpg");
Texture2D texture2 = new(Directory.GetCurrentDirectory() + "/2.jpg");


while (!window.ShouldClose())
{
    ProcessKeyboardInput();
    Vector3 cursorPos = window.GetCursorPos();
    ProcessMouseInput(cursorPos.X, cursorPos.Y);

    window.FrameCalculations();
    window.Clear(new Color(0.2f, 0.3f, 0.3f));

    texture.SetActive();
    window.Draw(rect);
    window.Draw(rect2); 
    
    texture2.SetActive();
    window.Draw(cube);

    window.Render();
}

// CAMERA MOVEMENT
// TODO: add enum with keys, and key statuses
void ProcessKeyboardInput()
{
    //if esc is pressed
    if(window.GetKey(256) == 1)
        window.Close();

    //if g is pressed
    if (window.GetKey(71) == 1)
        window.SetMouseInputMode(0x00034003); //disable cursor

    //if h is pressed
    if (window.GetKey(72) == 1)
        window.SetMouseInputMode(0x00034001); //enable cursor

    float cameraSpeed = 2.5f * window.DeltaTime;
    Vector3 cameraPos = new Vector3(0, 0, 0);

    if (window.GetKey(87) == 1) //w
        cameraPos += window.Camera.CameraFront * cameraSpeed;
    if (window.GetKey(83) == 1) //s
        cameraPos -= window.Camera.CameraFront * cameraSpeed;
    if (window.GetKey(65) == 1) //a
        cameraPos -= window.Camera.CameraRight * cameraSpeed;
    if (window.GetKey(68) == 1) //d
        cameraPos += window.Camera.CameraRight * cameraSpeed;
  
    window.Camera.Transform.Position = window.Camera.Transform.Position + cameraPos;
}

void ProcessMouseInput(float xpos, float ypos)
{
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    window.Camera.Transform.Rotation = window.Camera.Transform.Rotation + new Vector3(0, yoffset, xoffset);
}