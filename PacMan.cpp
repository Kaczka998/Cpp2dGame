#include "PacMan.h"


PacMan::PacMan(float posX, float posY, float speed, String nameOfFile) :
	Ghost(posX, posY, speed, nameOfFile)
{
	this->pacMan = true;
	this->speed = 0.12f;
}

void PacMan::movePacMan()
{
	if (!collision)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			this->setTexture("pacManIconLeft.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(-(this->speed), 0.00f);
			this->currentDirection = Keyboard::Key::Left;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			this->setTexture("pacManIcon.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move((this->speed), 0.00f);
			this->currentDirection = Keyboard::Key::Right;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		{

			this->setTexture("pacManIconUp.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, -(this->speed));
			this->currentDirection = Keyboard::Key::Up;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			this->setTexture("pacManIconDown.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, (this->speed));
			this->currentDirection = Keyboard::Key::Down;
		}
	}
	if (collision)
	{
		if (Keyboard::isKeyPressed(this->currentDirection))
		{
			/*if (this->currentDirection == 71 && collision) {
				this->imageObject.move(0.51f,0.0f);
				cout << collision << endl;
				collision = false;
			}
			if (this->currentDirection == 72 && collision) {
				this->imageObject.move(-0.51f, 0.0f);
				cout << collision << endl;
				collision = false;
			}
			if (this->currentDirection == 73 && collision) {
				this->imageObject.move(0.0f, 0.51f);
				cout << collision << endl;
				collision = false;
			}
			if (this->currentDirection == 74 && collision) {
				this->imageObject.move(0.0f, -0.51f);
				cout << collision << endl;
				collision = false;
			}*/

		}
		else if (!Keyboard::isKeyPressed(this->currentDirection))
		{
			collision = false;
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			{
				this->setTexture("pacManIconLeft.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = Keyboard::Key::Left;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			{
				this->setTexture("pacManIcon.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move((this->speed), 0.00f);
				this->currentDirection = Keyboard::Key::Right;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			{
				this->setTexture("pacManIconUp.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = Keyboard::Key::Up;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			{
				this->setTexture("pacManIconDown.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = Keyboard::Key::Down;
			}
			while (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				this->imageObject.setPosition(280.0f, 540.0f);
			}
		}

	}
}

void PacMan::killPacMan()
{
	numberOfLifes--;
}

PacMan::~PacMan() {}
