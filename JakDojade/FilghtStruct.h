#pragma once
#include "OwnString.h"

struct Flight{
	OwnString from;
	OwnString to;
	int distance;
	int if_setted = 0;
};