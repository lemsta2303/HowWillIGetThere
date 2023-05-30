#pragma once

#include "OwnString.h"
#include "OwnVector.h"
#include "OwnQueue.h"

class City {
private:
	OwnString name;
	int x_position;
	int y_position;
	int index;
public:
	City();
	void addLetterToName(char letter);
	void setCityName(OwnString city_name);
	int getXPosition() const;
	int getYPosition() const;
	int getIndex() const;
	OwnString getName() const;
	void setXPosition(int x);
	void setYPosition(int y);
	void setIndex(int i);
	void clearName();
	bool checkIfThisCityByName(OwnString comparing_name);
	void printCity();
	void printCityName();
	~City();
};