#pragma once

#define EXPORT __declspec(dllexport)

#include "graphicsObject.h"

extern "C" {
	EXPORT GraphicsObject* GraphicsObject_create() {
		return new GraphicsObject();
	}

	EXPORT Color GrahpicsObject_getColor(GraphicsObject* graphics){
		return graphics->color;
	}
	EXPORT void GraphicsObject_setColor(GraphicsObject* graphics, Color color) {
		graphics->color = color;
	}

	EXPORT Transform GraphicsObject_getTransform(GraphicsObject* graphics) {
		return graphics->transform;
	}
	EXPORT void GraphicsObject_setTransform(GraphicsObject* graphics, Transform transform) {
		graphics->transform = transform;
	}
	
	EXPORT Texture2D* GraphicsObject_getTexture(GraphicsObject* graphics) {
		return graphics->texture;
	}
	EXPORT void GraphicsObject_setTexture(GraphicsObject* graphics, Texture2D* texture) {
		graphics->texture = texture;
	}
	
	EXPORT Geometry* GraphicsObject_getGeometry(GraphicsObject* graphics) {
		return graphics->geometry;
	}
	EXPORT void GraphicsObject_setGeometry(GraphicsObject* graphics, Geometry* geometry) {
		graphics->geometry = geometry;
	}
}