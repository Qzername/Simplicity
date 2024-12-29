#include "color.h"

Color::Color(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->w = 255;
}

Color::Color() : Color(255, 255, 255) {

}

Color::Color(float r, float g, float b, float w) : Color(r,g,b) {
	this->w = w;
}