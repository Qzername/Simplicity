#include "color.h"

Color::Color(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->w = 1.0f;
}

Color::Color() : Color(1.0f, 1.0f, 1.0f) {

}

Color::Color(float r, float g, float b, float w) : Color(r,g,b) {
	this->w = w;
}