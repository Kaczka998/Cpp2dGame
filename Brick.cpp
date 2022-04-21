#include "Brick.h";

Brick::Brick(float posX, float posY, String nameOfImage) : Object(posX, posY, nameOfImage)
{
	this->setTexture(nameOfImage);
}
