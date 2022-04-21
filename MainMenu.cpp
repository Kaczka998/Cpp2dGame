#include "MainMenu.h";

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
		exit(-1);
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Blue);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2 - 40, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Sound");
	menu[1].setPosition(Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Quit");
	menu[2].setPosition(Vector2f(width / 2 - 40, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Blue);
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Blue);
	}
}