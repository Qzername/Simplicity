#include "canvas.h"
#include "Geometries.h"

Canvas::Canvas() : renderer(nullptr) {}
Canvas::Canvas(Renderer* renderer) : renderer(renderer) {}

void Canvas::DrawWheel(vector3 center, float radius) {

	GraphicsObject wheel;
	wheel.geometry = Geometries::wheel(16,radius);
	wheel.transform.setPosition(center);
	wheel.transform.scale = vector3(radius, radius, 1.0f);
	renderer->Render(wheel);
}

void Canvas::DrawRectangle(vector3 topLeft, vector3 bottomRight) {
	GraphicsObject rectangle;
	rectangle.geometry = Geometries::rectangle(bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
	rectangle.transform.setPosition((topLeft + bottomRight) * 0.5f);
	renderer->Render(rectangle);
}

void Canvas::DrawCube(vector3 center) {
	GraphicsObject cube;
	cube.geometry = Geometries::cube();
	cube.transform.setPosition(center);
	renderer->Render(cube);	
}