#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Engine.h"
#include <SFML/Audio.hpp>
#include<list>
using namespace std;
using namespace sf;

void Engine::collisionPacManGhost(PacMan* pacMan1, Ghost* ghost1, Results* results)
{

	pacMan1->movePacMan();
	if (pacMan1->imageObject.getGlobalBounds().intersects(ghost1->imageObject.getGlobalBounds()))
	{

		Music hitGhost;

		if (!hitGhost.openFromFile("../../Music/Ghost.wav"))
		{
			cout << "Blad podczas ladowania muzyki" << endl;
		}
		pacMan1->collision = true;
		if (sound)
		{
			hitGhost.setPitch(1.5f);
			hitGhost.play();
		}

		pacMan1->imageObject.setPosition(280.0f, 540.0f);
		results->lostLife();
		results->showResult();
		Sleep(382);
	}
}

void Engine::collisionPacManFood(PacMan* pacMan1, Food* food1, Map* map, Results* results)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(food1->imageObject.getGlobalBounds()))
	{
		Music fruit;
		if (!fruit.openFromFile("../../Music/Fruit.wav"))
		{
			cout << "Blad podczas ladowania muzyki" << endl;
		}

		if (sound)
		{
			//fruit.setPitch(1.5f);
			fruit.play();
		}

		results->eatFood();
		results->showResult();
		map->tiles[(int)food1->imageObject.getPosition().x / 40][(int)food1->imageObject.getPosition().y / 40] = NULL;
		delete food1;
		Sleep(50);
	}
}

void Engine::collisionPacManBricks(Ghost* pacMan1, Brick* brick1)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(brick1->imageObject.getGlobalBounds()))
	{
		pacMan1->collision = true;
	}
}

void Engine::collisionGhostBricks(Ghost* ghost1, Brick* brick1)
{
	if (ghost1->imageObject.getGlobalBounds().intersects(brick1->imageObject.getGlobalBounds()))
	{
		ghost1->collision = true;
	}
}


bool Engine::display(RenderWindow* window, Color colorOfMap)
{
	Results* results = new Results();
	PacMan* pacMan = new PacMan((300.0f), (360.0f), 0.5f, "pacManIcon.png");
	int id = 0;
	Map* map = new Map();
	map->fillKindOfTilesArray();
	map->loadMap();
	map->loadGhost(3, 1, "orangeGhost.png", 0);
	map->loadGhost(2, 9, "blueGhost.png", 0);
	map->loadGhost(5, 5, "orangeGhost.png", 2);
	map->loadGhost(11, 5, "blueGhost.png", 2);
	map->loadGhost(16, 6, "orangeGhost.png", 0);
	Music intro;
	if (!intro.openFromFile("../../Music/intro.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	if (sound)
	{
		intro.play();
	}

	if (id == 0) {
		for (Ghost* gh : map->allGhosts)
		{
			gh->setID(id);
			id++;
		}
	}


	while (window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}
		if (results->numberOfLife == 0)
		{
			isRunning = false;
		}
		window->clear(colorOfMap);
		map->displayMap(window);
		window->draw(pacMan->imageObject);
		for (Ghost* gh : map->allGhosts)
		{
			collisionPacManGhost(pacMan, gh, results);
		}
		for (Food* fd : map->allFood)
		{
			collisionPacManFood(pacMan, fd, map, results);
		}
		for (Brick* bk : map->allBricks)
		{
			collisionPacManBricks(pacMan, bk);
		}
		for (Ghost* gh : map->allGhosts)
		{
			if (gh->getID() == 0 || gh->getID() == 4)
				gh->aiMoveGhost2(pacMan->imageObject.getPosition().x, pacMan->imageObject.getPosition().y,
					gh->imageObject.getPosition().x, gh->imageObject.getPosition().y, gh->currentDirection);
			if (gh->getID() == 1)
				gh->aiMoveGhostSmart(pacMan->imageObject.getPosition().x, pacMan->imageObject.getPosition().y,
					gh->imageObject.getPosition().x, gh->imageObject.getPosition().y, gh->currentDirection);
			if (gh->getID() == 2)
				gh->moveGhostLeft(gh->currentDirection);
			if (gh->getID() == 3)
				gh->moveGhostRight(gh->currentDirection);

			for (Brick* bk : map->allBricks)
			{
				collisionGhostBricks(gh, bk);
			}

		
		}
		//TEKST
		sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
			exit(-1);
		sf::Text textLife;
		sf::Text textPoints;
		textLife.setString("Lifes:"+to_string(results->numberOfLife));
		textPoints.setString("Points:" + to_string(results->howManyFoodAte));

	
		textLife.setCharacterSize(23 * (window->getSize().y / 1080.f));
		textLife.setFont(font);
		textLife.setFillColor(sf::Color::White);
		textPoints.setCharacterSize(23 * (window->getSize().y / 1080.f));
		textPoints.setFont(font);
		textPoints.setFillColor(sf::Color::White);
		
		textLife.setPosition(900, 200);
		window->draw(textLife);
		textPoints.setPosition(900, 400);
		window->draw(textPoints);
			
		
		
		window->display();

	}



	Music death;
	if (!death.openFromFile("../../Music/Death.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	if (sound)
	{
		death.play();
	}

	

	RenderWindow gameOverWindow(VideoMode(300, 150), "Game Over");

	
	while (gameOverWindow.isOpen())
	{
		Event event;
		
	
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			break;
		}

		window->clear();

		window->display();
	}



	//map->showkindOfTiles();
	system("pause");
	Sleep(1700);
	return false;


}


void Engine::startGame()
{
	sf::RenderWindow window(sf::VideoMode(880, 640), "Pac-Man Menu");

	MainMenu menu(window.getSize().x, window.getSize().y);
	Color colorOfMap = Color::Black;
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					{
						//std::cout << "Play button has been pressed" << std::endl;
						RenderWindow window2(VideoMode(980, 640), "Pac-Man");
						window.close();
						display(&window2, colorOfMap);
						if (!window2.isOpen())
						{
							window2.close();
						}
						break;
					}
					case 1:
					{
						sound = false;
						std::cout << "Option button has been pressed" << std::endl;
						break;
					}
					case 2:
					{
						window.close();
						break;
					}
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

	
		window.clear();

		menu.draw(window);


		window.display();
	}
	
}

void Engine::endGame()
{
	this->isRunning = false;
}