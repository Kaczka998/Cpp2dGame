#include <iostream>
#include <SFML\Graphics.hpp>
#include "Food.h";

using namespace std;

Food::Food(float posX, float posY, String nameOfImage) : Object(posX, posY, nameOfImage) {}
Food::~Food()
{
	eat();
}

void Food::eat()
{
	//cout << "Pozostalo: " << howManyFood << "sztuk jedzenia\n";
}
