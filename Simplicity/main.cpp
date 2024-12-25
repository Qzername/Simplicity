#include "mainLink.h"

#include "window.h"
#include "rectangle.h"
#include "color.h"
#include "texture2D.h"
#include "vector3.h"
#include "cube.h"
#include "camera.h"

Window window("Simplicity test window");

bool firstMouse = true;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// timing
float deltaTime = 144.0f/10000.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void processInput(GLFWwindow* windowID);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

int main()
{
    window.camera.transform.position = vector3(0, 0, -2);

    window.addKeyboardCallback(processInput);
    window.addCursorCallback(mouse_callback);

 /*   Texture2D texture = Texture2D("<path to file>");
    texture.SetActive();*/

    Rectangle rect(0.20f,0.20f,0.5f,0.5f);
    rect.transform.rotation = vector3(0.5f, 0.5f, 0.0f);

    Rectangle rect2(-0.5f, -0.5f, 0.1f, 0.1f);
    rect2.color = Color(0.0f, 0.0f, 1.0f);

    Cube cube(vector3(0.0f,0.0f,-1.0f), 1.0f);
    cube.transform.rotation = vector3(0.5f, 0.5f, 0.5f);

    window.addDrawable(&rect);
    window.addDrawable(&rect2);
    window.addDrawable(&cube);

    window.show();

    return 0;
}

void processInput(GLFWwindow* windowID)
{
    if (glfwGetKey(windowID, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(windowID, true);

    if (glfwGetKey(windowID, GLFW_KEY_G) == GLFW_PRESS)
        glfwSetInputMode(windowID, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (glfwGetKey(windowID, GLFW_KEY_H) == GLFW_PRESS)
        glfwSetInputMode(windowID, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    float cameraSpeed = static_cast<float>(2.5 * deltaTime);
    if (glfwGetKey(windowID, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(windowID, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(windowID, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(windowID, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    window.camera.transform.position = vector3(cameraPos.x, cameraPos.y, cameraPos.z);
    window.camera.cameraFront = cameraFront;
    window.camera.cameraUp = cameraUp;
}


void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
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

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}