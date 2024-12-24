#include "mainLink.h"

#include "window.h"
#include "rectangle.h"
#include "color.h"
#include "texture2D.h"
#include "vector3.h"

int main()
{
    Window window("Simplicity test window");

    Texture2D texture = Texture2D();
    texture.SetActive();

    Rectangle rect(0.20f,0.20f,0.5f,0.5f);
    rect.transform.rotation = vector3(0.5f, 0.5f, 0.0f);

    Rectangle rect2(-0.999f, -0.999f, 0.1f, 0.1f);
    rect2.color = Color(0.0f, 0.0f, 1.0f);

    window.addDrawable(&rect);
    window.addDrawable(&rect2);

    window.show();

    return 0;
}