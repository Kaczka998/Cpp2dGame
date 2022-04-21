#pragma once
#ifndef RESULTS_H
#define RESULTS_H

#include <iostream>;
using namespace std;

class Results
{
public:
	int howManyFoodAte;
	int numberOfLife;
	Results();
	void lostLife();
	void eatFood();
	void showResult();
};

#endif RESULTS_H

