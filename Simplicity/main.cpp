#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "rectangle.h"

int main()
{
    Window window("Simplicity test window");

    Rectangle rect(0.20f,0.20f,0.5f,0.5f);
    Rectangle rect2(-1.0f, -1.0f, 0.1f, 0.1f);

    window.addDrawable(&rect);
    window.addDrawable(&rect2);

    window.show();

    return 0;
}