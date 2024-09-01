#pragma once
#include "vector3.h"

class Drawable
{
public:
	vector3 position;

	virtual void Render() = 0;
};