#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Object
{

public:
	int width;
	int height;
	float posX;
	float posY;
	bool startOfGame = true;
	Texture texture;
	Sprite imageObject;

	Object(float posX = (50.0F), float posY = (50.0F), String nameOfImage = "pacManIcon.png");
	~Object();
	Texture getTexture();
	void setTexture(String nameOfImage);
};
#endif

