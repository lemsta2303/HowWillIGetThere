#pragma once
#include <iostream>

#include "OwnVector.h"
#include "City.h"

using namespace std;

class Board {
private:
	int width;
	int height;
	char** map;
	int city_counter;
	OwnVector<City> cities;
public:
	Board();
	int getCityCounter() const;
	City getCityAtPos(int index);
	int getWidth() const;
	int getHeight() const;
	char getMapField(int x, int y) const;
	void loadMap();
	bool checkIfPartOfCityName(int x, int y);
	OwnString loadCityName(int i, int j);
	void loadCities();
	void printCities();
	void printBoard();
	~Board();
};