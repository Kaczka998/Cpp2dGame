#include "Map.h";

Map::Map() {}

void Map::fillKindOfTilesArray()
{
	for (int y = 0; y < y_tiles; y++)
	{
		for (int x = 0; x < x_tiles; x++)
		{
			kindOfTiles[x][y] = 0;
			tiles[x][y] = NULL;
		}
	}
}

void Map::showkindOfTiles()
{
	for (int y = 0; y < y_tiles; y++)
	{
		for (int x = 0; x < x_tiles; x++)
		{
			cout << kindOfTiles[x][y] << "   ";
		}
		cout << endl;
	}
}

void Map::loadOneBrick(int x, int y)
{
	Brick* brick = new Brick(((float)x) * (this->tile_width), ((float)y) * (this->tile_height), "brick3.jpg");
	tiles[x][y] = &brick->imageObject;
	kindOfTiles[x][y] = 1;
	allBricks.push_back(brick);
}

void Map::loadAllBricks()
{
	for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			if (x == 0 || y == 0 || x == ((this->x_tiles) - 1) || y == ((this->y_tiles) - 1))
			{
				loadOneBrick(x, y);
			}
			if (((x > 4 && x < 10) && y == 10) || ((x > 11 && x < 16) && y == 10) || ((x > 17 && x < 21) && y == 10))
			{
				loadOneBrick(x, y);
			}
			if (((y > 2 && y < 9) && x == 3) || ((y > 11 && y < 15) && x == 8) || ((y > 16 && y < 20) && x == 10))
			{
				loadOneBrick(x, y);
			}
			if (((x > 1 && x < 6) && (y == 12)) || (x == 5 && y > 12))
			{
				loadOneBrick(x, y);
			}
			if (((x > 9 && x < 13) && (y == 13)) || ((x > 15 && x < 18) && (y == 13)))
			{
				loadOneBrick(x, y);
			}
			if (((y > 11 && y < 16) && x == 14) || ((y > 11 && y < 16) && x == 19))
			{
				loadOneBrick(x, y);
			}
			if (((x > 4 && x < 9) && y == 3) || ((x > 11 && x < 15) && y == 3) || ((x > 17 && x < 20) && y == 3))
			{
				loadOneBrick(x, y);
			}
			if (((y > 0 && y < 6) && x == 16) || (x == 10 && (y > 1 && y < 8)))
			{
				loadOneBrick(x, y);
			}
			if (((x == 6 || x == 7) && y == 5) || ((x == 6 || x == 7) && y == 6) || ((x == 6 || x == 7) && y == 7) || ((x == 6 || x == 7) && y == 8))
			{
				loadOneBrick(x, y);
			}
			if (((y == 7 || y == 8) && x == 18) || ((x == 16 || x == 17) && y == 7) || ((x == 16 || x == 17) && y == 8))
			{
				loadOneBrick(x, y);
			}
			if ((x == 13 && (y > 4 && y < 9)))//|| (x == 13 && (y>8 && y<14)))
			{
				loadOneBrick(x, y);
			}
		}
	}
}

void Map::loadOneFood(int x, int y)
{
	float posX = ((float)x) * (this->tile_width) + 20;
	float posY = ((float)y) * (this->tile_height) + 20;
	Food* food = new Food(posX, posY, "food.png");
	tiles[x][y] = &food->imageObject;
	kindOfTiles[x][y] = 2;
	allFood.push_back(food);
}

void Map::loadAllFood()
{
	int posX;
	int posY;
	int howManyFood = 0;
	srand(time(NULL));


	while (howManyFood < 25)       //render some food 
	{
		posX = (rand() % 20) + 2;
		posY = (rand() % 14) + 2;
		if (kindOfTiles[posX][posY] == 0)
		{
			loadOneFood(posX, posY);
			howManyFood++;
		}
	}


	/*for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			if (x == 2 && y > 1 && y < 8)       //set some food
			{
				loadOneFood(x, y);
			}
		}
	}*/
}

void Map::loadGhost(int x, int y, String nameOfImage, int direction)
{
	Ghost* ghost = new Ghost(((float)x) * (this->tile_width), ((float)y) * (this->tile_height), 0.12f, nameOfImage, direction);
	tiles[x][y] = &ghost->imageObject;
	kindOfTiles[x][y] = 3;
	allGhosts.push_back(ghost);
}

void Map::loadMap()
{
	loadAllBricks();
	loadAllFood(); //have to be call as last in loadMap()
}

void Map::displayMap(RenderWindow* window)
{
	for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			if (this->tiles[x][y] != NULL)
			{
				window->draw(*(this->tiles[x][y]));
			}
		}
	}
}