#include <Window.h> 
#include <Graphics/Objects/GraphicsObject.h>
#include <Graphics/Geometries/Geometries.h>

Window window("Model loading example");
GraphicsObject model; 

void OnFrame()
{
    window.graphics.renderer.Clear();
    window.graphics.renderer.Render(model);
}

int main()
{
    window.graphics.camera.transform.setPosition({ 0,0,-10 });
	window.graphics.renderer.backgroundColor = { 50, 75, 75 };

	//this needs to be a total path for example: C:/somefolder/ModelLoadingExample/pillar.obj
    model.geometry = Geometries::loadModel("[path]/Simplicity/Simplicity/Examples/ModelLoadingExample/pillar.obj");
    model.transform.setEulerRotation({ 30,0,45 });

    window.setOnFrameCallback(OnFrame);

    window.show();

    return 0;
}