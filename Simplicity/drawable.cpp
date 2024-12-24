#include "drawable.h"
#include "color.h"

Drawable::Drawable(float x, float y){
    vector3 position;
    
    position.x = x;
    position.y = y;
    position.z = 0;

    this->transform = Transform(position);

    //default color (white)
    Color color;
    this->color = color;
}