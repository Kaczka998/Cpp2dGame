#include "pacman/Object.h";

Object::Object(float posX, float posY, String nameOfImage)
{
	this->posX = posX;
	this->posY = posY;
	setTexture(nameOfImage);
}

Object::~Object() {}

void Object::setTexture(String nameOfImage)
{
	if (!this->texture.loadFromFile("Graphics/" + nameOfImage))
	{
		cout << "Cos poszlo nie tak - plik nie zostal otwarty\n";
		system("exit");
	}
	imageObject.setTexture(this->texture);
	if (Object::startOfGame)
	{
		this->width = imageObject.getTexture()->getSize().x;
		this->height = imageObject.getTexture()->getSize().y;
		imageObject.setPosition(posX, posY);
		startOfGame = false;
	}

}

Texture Object::getTexture()
{
	return this->texture;
}
