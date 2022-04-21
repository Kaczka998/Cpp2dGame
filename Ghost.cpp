#include "Ghost.h"

Ghost::Ghost(float posX, float posY, float speed, String nameOfFile, int direction) : Object(posX, posY, nameOfFile)
{
	this->posX = posX;
	this->posY = posY;
	this->oldPosX = posX;
	this->oldPosY = posY;
	this->pacMan = false;
	this->collision = false;
	this->speed = 0.5f;
	this->currentDirection = direction;
}
Ghost::~Ghost()
{
	cout << "Niszczenie obiektu ducha";
}

void Ghost::setID(int id) {
	this->id = id;
}

int Ghost::getID() {
	return this->id;
}

void Ghost::moveGhostRight(int direction)
{
	if (!collision)
	{
		switch (direction)
			{
			case 0:
			{
				this->imageObject.move(this->speed, 0.00f);
				this->currentDirection = 0;
				break;
			}
			case 1:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = 1;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = 2;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = 3;
				break;
			}
		}
	}
	if (collision)
	{
		
		int changeDirection = this->currentDirection;

		switch (changeDirection)
		{
			case 0:
			{
				this->imageObject.move(0.00f, this->speed);
				this->collision = false;
				this->currentDirection = 2;
				break;
			
			}
			case 1:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->collision = false;
				this->currentDirection = 3;
				break;
			
			}
			case 2:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 1;
				break;
			}
			case 3:
			{
				this->imageObject.move((this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 0;
				break;
			}
		}
	}
}

void Ghost::moveGhostLeft(int direction)
{

	if (!collision)
	{
		switch (direction)
		{
			case 0:
			{
				this->imageObject.move(this->speed, 0.00f);
				this->currentDirection = 0;
				break;
			}
			case 1:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = 1;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = 2;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = 3;
				break;
			}
		}
	}
	if (collision)
	{

		int changeDirection = this->currentDirection;

		switch (changeDirection)
		{
			case 0:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->collision = false;
				this->currentDirection = 3;
				break;
			}
			case 1:
			{
				this->imageObject.move(0.00f, this->speed);
				this->collision = false;
				this->currentDirection = 2;
				break;
			}
			case 2:
			{
				this->imageObject.move((this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 0;
				break;			
			}
			case 3:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 1;
				break;
			}
		}
	}

}

float Ghost::distance(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2) {
	float distance;
	float centerX1 = x1 + (width1 / 2.0);
	float centerY1 = y1 + (height1 / 2.0);
	float centerX2 = x2 + (width2 / 2.0);
	float centerY2 = y2 + (height2 / 2.0);

	distance = sqrt(pow(centerX2 - centerX1, 2) + pow(centerY2 - centerY1, 2));

	return distance;
}

void Ghost::aiMoveGhost2(float posXPacman, float posYPacman, float posXGhost, float posYGhost, int direction) {
	float offSetWithMove = 10;
	float distanceFromMoveToRight = distance(posXGhost + offSetWithMove, posYGhost, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToLeft = distance(posXGhost - offSetWithMove, posYGhost, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToUp = distance(posXGhost, posYGhost - offSetWithMove, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToDown = distance(posXGhost, posYGhost + offSetWithMove, 35, 35, posXPacman, posYPacman, 35, 35);
	int changeDirection = this->currentDirection;

	if (!collision)
	{
		
		switch (direction)
		{
			case 0:
			{
				this->imageObject.move(this->speed, 0.00f);
				this->currentDirection = 0;
				break;
			}
			case 1:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = 1;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = 2;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = 3;
				break;
			}
		}
	}
	if (collision)
	{

		

		if (this->currentDirection == 0) {
			if (distanceFromMoveToLeft <= distanceFromMoveToUp
				&& distanceFromMoveToLeft < distanceFromMoveToDown) 
				changeDirection = 1;
			if (distanceFromMoveToUp <= distanceFromMoveToLeft
				&& distanceFromMoveToUp < distanceFromMoveToDown) 
				changeDirection = 3;		
			if (distanceFromMoveToDown <= distanceFromMoveToLeft
				&& distanceFromMoveToDown < distanceFromMoveToUp) 
				changeDirection = 2;				
		}

		if (this->currentDirection == 1) {
			if (distanceFromMoveToRight <= distanceFromMoveToUp
				&& distanceFromMoveToRight < distanceFromMoveToDown) 
				changeDirection = 0;
			if (distanceFromMoveToUp <= distanceFromMoveToRight
				&& distanceFromMoveToUp < distanceFromMoveToDown) 
				changeDirection = 3;
			if (distanceFromMoveToDown <= distanceFromMoveToRight
				&& distanceFromMoveToDown < distanceFromMoveToUp) 
				changeDirection = 2;
		}

		if (this->currentDirection == 3) {
			if (distanceFromMoveToLeft <= distanceFromMoveToRight
				&& distanceFromMoveToLeft < distanceFromMoveToDown) 
				changeDirection = 1;				
			if (distanceFromMoveToRight <= distanceFromMoveToLeft
				&& distanceFromMoveToRight < distanceFromMoveToDown) 
				changeDirection = 0;				
			if (distanceFromMoveToDown <= distanceFromMoveToRight
				&& distanceFromMoveToDown < distanceFromMoveToLeft) 
				changeDirection = 2;				
		}

		if (this->currentDirection == 2) {
			if (distanceFromMoveToLeft <= distanceFromMoveToRight
				&& distanceFromMoveToLeft < distanceFromMoveToUp) 
				changeDirection = 1;				
			if (distanceFromMoveToRight <= distanceFromMoveToLeft
				&& distanceFromMoveToRight < distanceFromMoveToUp) 
				changeDirection = 0;				
			if (distanceFromMoveToUp <= distanceFromMoveToRight
				&& distanceFromMoveToUp < distanceFromMoveToLeft) 
				changeDirection = 3;		
		}

		switch (direction)
		{
			case 0:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 1:
			{
				this->imageObject.move((this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, this->speed);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
		}
	}
}

void Ghost::aiMoveGhostSmart(float posXPacman, float posYPacman, float posXGhost, float posYGhost, int direction) {
	float offSetWithMove = 10;
	float distanceFromMoveToRight = distance(posXGhost + offSetWithMove, posYGhost, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToLeft = distance(posXGhost - offSetWithMove, posYGhost, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToUp = distance(posXGhost, posYGhost - offSetWithMove, 35, 35, posXPacman, posYPacman, 35, 35);
	float distanceFromMoveToDown = distance(posXGhost, posYGhost + offSetWithMove, 35, 35, posXPacman, posYPacman, 35, 35);
	int changeDirection = this->currentDirection;
	int changePosXGhost = posXGhost;
	int changePosYGhost = posYGhost;
	if (!collision)
	{
		//if (changePosXGhost % 35 == 0 && changePosYGhost % 35 == 0) {
			if (distanceFromMoveToRight < distanceFromMoveToLeft && distanceFromMoveToRight < distanceFromMoveToUp
				&& distanceFromMoveToRight < distanceFromMoveToDown) {
				changeDirection = 0;
			}
			if (distanceFromMoveToLeft < distanceFromMoveToRight && distanceFromMoveToLeft < distanceFromMoveToUp
				&& distanceFromMoveToLeft < distanceFromMoveToDown) {
				changeDirection = 1;
			}
			if (distanceFromMoveToUp < distanceFromMoveToRight && distanceFromMoveToUp < distanceFromMoveToLeft
				&& distanceFromMoveToUp < distanceFromMoveToDown) {
				changeDirection = 3;
			}
			if (distanceFromMoveToDown < distanceFromMoveToRight && distanceFromMoveToDown < distanceFromMoveToLeft
				&& distanceFromMoveToDown < distanceFromMoveToUp) {
				changeDirection = 2;
			}
		//}

		switch (direction)
		{
			case 0:
			{
				this->imageObject.move(this->speed, 0.00f);
				this->currentDirection = changeDirection;
				break;
			}
			case 1:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = changeDirection;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = changeDirection;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = changeDirection;
				break;
			}
		}
	}
	if (collision)
	{

		if (this->currentDirection == 0) {
			if (distanceFromMoveToLeft <= distanceFromMoveToUp
				&& distanceFromMoveToLeft < distanceFromMoveToDown)
				changeDirection = 1;
			if (distanceFromMoveToUp <= distanceFromMoveToLeft
				&& distanceFromMoveToUp < distanceFromMoveToDown)
				changeDirection = 3;
			if (distanceFromMoveToDown <= distanceFromMoveToLeft
				&& distanceFromMoveToDown < distanceFromMoveToUp)
				changeDirection = 2;
		}

		if (this->currentDirection == 1) {
			if (distanceFromMoveToRight <= distanceFromMoveToUp
				&& distanceFromMoveToRight < distanceFromMoveToDown)
				changeDirection = 0;
			if (distanceFromMoveToUp <= distanceFromMoveToRight
				&& distanceFromMoveToUp < distanceFromMoveToDown)
				changeDirection = 3;
			if (distanceFromMoveToDown <= distanceFromMoveToRight
				&& distanceFromMoveToDown < distanceFromMoveToUp)
				changeDirection = 2;
		}

		if (this->currentDirection == 3) {
			if (distanceFromMoveToLeft <= distanceFromMoveToRight
				&& distanceFromMoveToLeft < distanceFromMoveToDown)
				changeDirection = 1;
			if (distanceFromMoveToRight <= distanceFromMoveToLeft
				&& distanceFromMoveToRight < distanceFromMoveToDown)
				changeDirection = 0;
			if (distanceFromMoveToDown <= distanceFromMoveToRight
				&& distanceFromMoveToDown < distanceFromMoveToLeft)
				changeDirection = 2;
		}

		if (this->currentDirection == 2) {
			if (distanceFromMoveToLeft <= distanceFromMoveToRight
				&& distanceFromMoveToLeft < distanceFromMoveToUp)
				changeDirection = 1;
			if (distanceFromMoveToRight <= distanceFromMoveToLeft
				&& distanceFromMoveToRight < distanceFromMoveToUp)
				changeDirection = 0;
			if (distanceFromMoveToUp <= distanceFromMoveToRight
				&& distanceFromMoveToUp < distanceFromMoveToLeft)
				changeDirection = 3;
		}

		switch (direction)
		{
			case 0:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 1:
			{
				this->imageObject.move((this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, this->speed);
				this->collision = false;
				this->currentDirection = changeDirection;
				break;
			}
		}
	}
}