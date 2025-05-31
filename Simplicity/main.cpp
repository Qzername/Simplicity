/*
#include "windowLink.h"
#include "transformLink.h"
#include "cameraLink.h"
#include "sceneLink.h"

#include "texture2DLink.h"

#include "drawableLink.h"

#include "cubeLink.h"
#include "rectangleLink.h"
#include "modelLink.h"
*/

// debug

#include "window.h"
#include "scene.h"
#include "Geometries.h"

#include <vector>

using namespace std;

void frameCallback();

Window window("test window");

GraphicsObject object;
Scene scene;

int main()
{
	object.color = Color(255, 0, 0);
	object.geometry = Geometries::cube();

	scene.Instantiate(&object);

	window.graphics.renderer.backgroundColor = Color(0, 0, 0);
	window.graphics.camera.transform.setPosition(vector3(0, 0, -3));
	window.graphics.camera.transform.setEulerRotation(vector3(0, 10, 0));

	window.setOnFrameCallback(frameCallback);
	window.show();

	return 0;
}

void frameCallback()
{
	window.graphics.renderer.Clear();
	scene.Render(window.graphics.renderer);
}