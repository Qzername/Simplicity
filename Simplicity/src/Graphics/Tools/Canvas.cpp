#include <Graphics/Tools/Canvas.h>
#include <Graphics/Geometries/Geometries.h>
#include <Graphics/Objects/GraphicsObject.h>

Canvas::Canvas() : renderer(nullptr) {}
Canvas::Canvas(Renderer* renderer) : renderer(renderer) {}

void Canvas::DrawWheel(Vector3 center, float radius) {

	GraphicsObject wheel;
	wheel.geometry = Geometries::wheel(16,radius);
	wheel.transform.setPosition(center);
	wheel.transform.scale = Vector3(radius, radius, 1.0f);
	renderer->Render(wheel);
}

void Canvas::DrawRectangle(Vector3 topLeft, Vector3 bottomRight) {
	GraphicsObject rectangle;
	rectangle.geometry = Geometries::rectangle(bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
	rectangle.transform.setPosition((topLeft + bottomRight) * 0.5f);
	renderer->Render(rectangle);
}

void Canvas::DrawCube(Vector3 center) {
	GraphicsObject cube;
	cube.geometry = Geometries::cube();
	cube.transform.setPosition(center);
	renderer->Render(cube);	
}