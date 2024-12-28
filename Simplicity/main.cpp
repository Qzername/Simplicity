#include "windowLink.h"
#include "rectangleLink.h"
#include "cameraLink.h"


#include "window.h"
#include "rectangle.h"
#include "color.h"
#include "texture2D.h"
#include "vector3.h"
#include "cube.h"
#include "camera.h"

Window window("Simplicity test window");

bool firstMouse = true;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;

void processKeyboardInput();
void processMouseInput(double xposIn, double yposIn);

int main()
{
    window.camera.transform.position = vector3(0, 0, -2);
    window.camera.transform.rotation = vector3(0, 0, 90);

    /*Texture2D texture = Texture2D("");
    Texture2D texture2 = Texture2D("");*/

    Rectangle rect(0.20f, 0.20f, 0.5f, 0.5f);
    rect.transform.rotation = vector3(0.5f, 0.5f, 0.0f);

    Rectangle rect2(0, 0, 1, 1);
    rect2.color = Color(0.0f, 0.0f, 1.0f);

    Cube cube(vector3(0.0f, 0.0f, -1.0f), 1.0f);
    cube.transform.rotation = vector3(0.5f, 0.5f, 0.5f);

    while (!window.shouldClose())
    {
        cout << "--------------------------------" << endl;
        cout << window.camera.transform.rotation.x << endl;
        cout << window.camera.transform.rotation.y << endl;
        cout << window.camera.transform.rotation.z << endl;

        processKeyboardInput();

        vector3 mousePos = window.getCursorPos();
        processMouseInput(mousePos.x, mousePos.y);

        window.frameCalculations();
        window.clear(Color(0.2f, 0.3f, 0.3f, 1.0f));

        //texture.SetActive();
        //window.draw(&rect);
        window.draw(&rect2);

        //texture2.SetActive();
       // window.draw(&cube);

        window.render();
    }

    return 0;
}

void processKeyboardInput()
{
    if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
        window.close();

    if (window.getKey(GLFW_KEY_G) == GLFW_PRESS)
        window.setMouseInputMode(GLFW_CURSOR_DISABLED);

    if (window.getKey(GLFW_KEY_H) == GLFW_PRESS)
        window.setMouseInputMode(GLFW_CURSOR_NORMAL);

    float cameraSpeed = static_cast<float>(2.5 * window.deltaTime);
    vector3 cameraPos = vector3(0, 0, 0);

    if (window.getKey(GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += window.camera.cameraFront * cameraSpeed;
    if (window.getKey(GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= window.camera.cameraFront * cameraSpeed;
    if (window.getKey(GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= window.camera.cameraRight * cameraSpeed;
    if (window.getKey(GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += window.camera.cameraRight * cameraSpeed;

    window.camera.transform.position = window.camera.transform.position + vector3(cameraPos.x, cameraPos.y, cameraPos.z);
}


void processMouseInput(double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    window.camera.transform.rotation.z += xoffset;
    window.camera.transform.rotation.y += yoffset;
}