#pragma once
#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Food : public Object
{
public:
	Food(float posX = 55.0f, float posY = 50.0f, String nameOfImage = "food.png");
	~Food();
	void eat();
};
#endif

