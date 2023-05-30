#pragma once

#include "OwnVector.h"
#include "City.h";

struct Node {
	City node_city;
	int distance;
	void setDistance(int x)
	{
		distance = x;
	}
};

