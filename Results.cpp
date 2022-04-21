#include "Results.h";

Results::Results()
{
	numberOfLife = 3;
	howManyFoodAte = 0;
}

void Results::lostLife()
{
	numberOfLife--;
}

void Results::eatFood()
{
	this->howManyFoodAte++;
}
void Results::showResult()
{
	system("cls");
	cout << "Zdobyto: " << howManyFoodAte << "punktow" << endl;
	cout << "Pozostalo: " << numberOfLife << " szans" << endl;
}