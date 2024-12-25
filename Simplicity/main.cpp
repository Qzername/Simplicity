#include "mainLink.h"

#include "window.h"
#include "rectangle.h"
#include "color.h"
#include "texture2D.h"
#include "vector3.h"
#include "cube.h"
#include "camera.h"

int main()
{
    Window window("Simplicity test window");

    window.camera.transform.position = vector3(0, 0, -2);

    Texture2D texture = Texture2D();
    texture.SetActive();

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