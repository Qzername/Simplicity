#include <Window.h>
#include <Graphics/Geometries/Geometries.h>
#include <Vector3.h>

//for camera movement
bool firstMouse = true;
float lastX = 400, lastY = 300;
Vector3 mousePos;

Window window("Objects showcase");
Renderer& renderer = window.graphics.renderer;

void OnFrame();
void ProcessKeyboardInput();
void ProcessMouseInput();	

GraphicsObject rectangle, cube, wheel;

int main()
{
	window.graphics.camera.transform.setPosition({ 0,0,-3 });
	renderer.backgroundColor = { 50, 150, 150 };

	rectangle.geometry = Geometries::rectangle(0.5f, 0.5f);
	rectangle.transform.setPosition({ -1, 0.5f, 0 });

	cube.geometry = Geometries::cube();
	cube.transform.setEulerRotation({ 45,0,45 });
	cube.color = {50,50,255};

	wheel.geometry = Geometries::wheel(32, 0.5f);
	wheel.transform.setPosition({ -2,-1,0 });

	window.setOnFrameCallback(OnFrame);

    window.show();

    return 0;
}

void OnFrame()
{
	ProcessKeyboardInput();
	ProcessMouseInput();

	renderer.Clear();
	renderer.Render(rectangle);
	renderer.Render(cube);
	renderer.Render(wheel);
}

void ProcessKeyboardInput() 
{
    auto input = window.input;
    auto camera = window.graphics.camera;

    if (input.GetButton(KeyCode::ESCAPE) == KeyStatus::PRESSED)
        window.close();

	//TODO: create enum in library for mouse input modes
    if (input.GetButton(KeyCode::G) == KeyStatus::PRESSED)
        input.setMouseInputMode(0x00034003);

    if (input.GetButton(KeyCode::H) == KeyStatus::PRESSED)
        input.setMouseInputMode(0x00034001);

    float cameraSpeed = 2.5f * window.deltaTime;
    Vector3 cameraPos = { 0, 0, 0 };
    
    //TODO: WASD not working
    if (input.GetButton(KeyCode::W) == KeyStatus::PRESSED)
        cameraPos += camera.transform.getForward() * cameraSpeed;
    if (input.GetButton(KeyCode::S) == KeyStatus::PRESSED)
        cameraPos -= camera.transform.getForward() * cameraSpeed;
    if (input.GetButton(KeyCode::A) == KeyStatus::PRESSED)
        cameraPos += camera.transform.getRight() * cameraSpeed;
    if (input.GetButton(KeyCode::D) == KeyStatus::PRESSED)
        cameraPos -= camera.transform.getRight() * cameraSpeed;

    if (input.GetButton(KeyCode::SPACE) == KeyStatus::PRESSED)
        cameraPos += camera.transform.getUp() * cameraSpeed;
    if (input.GetButton(KeyCode::LEFTCONTROL) == KeyStatus::PRESSED)
        cameraPos -= camera.transform.getUp() * cameraSpeed;

    camera.transform.setPosition(camera.transform.getPosition() + cameraPos);
}

void ProcessMouseInput() 
{
    Vector2 vector3 = window.input.GetCursorPosition();

    float xpos = vector3.x;
    float ypos = vector3.y;

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

    mousePos += { -yoffset, xoffset, 0 };

    window.graphics.camera.transform.setEulerRotation(mousePos);
}