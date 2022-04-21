#pragma once
#ifndef GHOST_H
#define GHOST_H
#include <SFML\Graphics.hpp>
#include "Object.h";
#include <iostream>

using namespace sf;
using namespace std;

class Ghost : public Object
{
public:
	bool pacMan;
	float speed;
	bool collision;
	int currentDirection;
	float oldPosX;
	float oldPosY;
	int id;
	Ghost(float posX = (120.0F), float posY = (200.0F), float speed = 0.03f, String nameOfFile = "orangeGhost.png", int direction = 1);
	~Ghost();
	void moveGhostRight(int direction);
	void moveGhostLeft(int direction);
	void aiMoveGhost2(float posXPacman, float posYPacman, float posXGhost, float posYGhost, int currentDirection);
	void aiMoveGhostSmart(float posXPacman, float posYPacman, float posXGhost, float posYGhost, int direction);
	float distance(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
	void setID(int id);
	int getID();
};
#endif // !GHOST_H


