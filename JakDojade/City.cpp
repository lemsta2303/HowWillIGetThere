#include <iostream>

#include "City.h"

using namespace std;

City::City()
{
	x_position = 0;
	y_position = 0;
	index = 0;
}

void City::addLetterToName(char letter)
{
	name.addLetter(letter);
}

void City::setCityName(OwnString city_name)
{
	name.setString(city_name.getWord(), city_name.getLength());
}

int City::getXPosition() const
{
	return x_position;
}

int City::getYPosition() const
{
	return y_position;
}

int City::getIndex() const
{
	return index;
}

OwnString City::getName() const
{
	return name;
}

void City::setXPosition(int x)
{
	x_position = x;
}

void City::setYPosition(int y)
{
	y_position = y;
}

void City::setIndex(int i)
{
	index = i;
}

void City::clearName()
{
	name.clearString();
}

bool City::checkIfThisCityByName(OwnString comparing_name)
{
	if (name.ifEqualString(comparing_name)) return true;
	else return false;
}

void City::printCity()
{
	cout << index << ". ";
	name.printString();
	cout << "(" << x_position << ", " << y_position << ")";
}

void City::printCityName()
{
	name.printString();
}

City::~City()
{
	name.~OwnString();
}