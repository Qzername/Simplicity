#include "drawable.h"
#include "color.h"

Drawable::Drawable(float x, float y){
    position.x = x;
    position.y = y;
    position.z = 0;

    //default color (white)
    Color color;
    this->color = color;
}