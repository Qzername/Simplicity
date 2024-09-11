#include "color.h"

color::color(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->w = 1.0f;
}

color::color() : color(1.0f, 1.0f, 1.0f) {

}

color::color(float r, float g, float b, float w) : color(r,g,b) {
	this->w = w;
}