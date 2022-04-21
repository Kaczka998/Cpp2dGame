#pragma once
#ifndef BRICK_H
#define BRICK_H

#include "Object.h";

class Brick : public Object
{
public:
	Brick(float posX, float posY, String nameOfImage = "brick2.jpg");
};

#endif


