#include <Window.h>
#include <Graphics/Geometries/Geometries.h>

void OnFrame();

Window window("Texture example");
GraphicsObject rect1, rect2, rect3;

int main()
{
    window.graphics.renderer.backgroundColor = { 50, 75, 75 };
    window.graphics.camera.transform.setPosition({ 0, 0, -3 });

    //this needs to be a total path for example: C:/somefolder/TextureExample/1.jog
    Texture2D texture = Texture2D::LoadFromFile("[path]/Simplicity/Simplicity/Examples/TextureExample/1.jpg");

    unsigned char textureData[12] = {
        255, 255, 255,
        0, 0, 0,
        255, 100, 100,
        100, 100, 100,
    };

	Texture2D texture2 = Texture2D::LoadFromData(2, 2, textureData, TextureFormat::RGB);

	rect1.geometry = Geometries::rectangle(0.5f, 0.5f);
    rect1.texture = &texture2;
    rect1.color = { 255, 0, 0 };

	rect2.geometry = Geometries::rectangle(0.5f, 0.5f);
    rect2.texture = &texture;
    rect2.transform.setPosition({ -0.5f, -0.5f, 0 });
    rect2.color = { 50, 50, 255 };

	rect3.geometry = Geometries::rectangle(0.5f, 0.5f);
    rect3.transform.setPosition({ -0.5f, 0, 0 });
    rect3.texture = &texture;

    window.setOnFrameCallback(OnFrame);

    window.show();

    return 0;
}

void OnFrame()
{
	Renderer& renderer = window.graphics.renderer;

    renderer.Clear();
    renderer.Render(rect1);
    renderer.Render(rect2);
	renderer.Render(rect3);
}