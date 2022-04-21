#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML\Graphics.hpp>

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class MainMenu
{
private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
public:
	MainMenu(float width, float height);
	~MainMenu();
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};

#endif MAINMENU_H


