#define NEW_LANE   10 

#include <iostream>

#include "Board.h"
#include "OwnVector.h"

using namespace std;

Board::Board()
{
	width = 0;
	height = 0;
	map = new char* [1];
	map[0] = new char;
	city_counter = 0;
}

int Board::getCityCounter() const
{
	return city_counter;
}

City Board::getCityAtPos(int index)
{
	return cities.getElement(index);
}

int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

char Board::getMapField(int x,int y) const
{
	return map[x][y];
}

void Board::loadMap()
{
	int w, h;
	char field = 'x';
	cin >> w;
	cin >> h;
	width = w;
	height = h;
	map = new char* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field = getchar();
			if (field != NEW_LANE)
			{
				map[i][j] = field;
			}
			else j--;
		}
	}
}

bool Board::checkIfPartOfCityName(int x, int y)
{
	if (map[x][y] != '*' && map[x][y] != '#' && map[x][y] != '.')
	{
		return true;
	}
	else return false;
}

OwnString Board::loadCityName( int i, int j)
{
	int if_city_next_to_first_letter = 0;
	int if_city_next_to_last_letter = 0;
	OwnString name_tmp;
	for (int m = -1; m <= 1; m++)
	{
		for (int n = -1; n <= 1; n++)
		{
			if (i + m >= 0 && i + m < height && j + n >= 0 && j + n < width && checkIfPartOfCityName(i+m,j+n)) // wyszukiwanie nazwy wokol gwiazdki
			{
				if (j + n - 1 == -1 || !checkIfPartOfCityName(i + m, j + n - 1))
				{
					if_city_next_to_first_letter = 1;
				}
				else if (j + n + 1 == width || !checkIfPartOfCityName(i + m, j + n + 1))
				{
					if_city_next_to_last_letter = 1;
				}
				if (if_city_next_to_first_letter)
				{
					int k = 0;
					while (j + n + k != width && checkIfPartOfCityName(i+m, j+n+k))
					{
						name_tmp.addLetter(map[i + m][j + n + k]);
						k++;
					}
					return name_tmp;
				}
				else if (if_city_next_to_last_letter)
				{
					int k = 0;
					while (j + n - k != 0 && checkIfPartOfCityName(i+m, j+n-k))
					{
						name_tmp.addLetter(map[i + m][j + n - k]);
						k++;
					}
					name_tmp.reverseWord();
					return name_tmp;
				}
			}
		}
	}
	return name_tmp; 
}

void Board::loadCities()
{
	City tmp_city;
	int index = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == '*')
			{
				city_counter++;
				tmp_city.setXPosition(i);
				tmp_city.setYPosition(j);
				tmp_city.setIndex(index);
				tmp_city.setCityName(loadCityName(i,j));		
				cities.push(tmp_city);
				index++;
			}
		}
	}
}

void Board::printCities()
{
	for (int i = 0; i < cities.getSize(); i++)
	{
		cities.getElement(i).printCity();
	}
}

void Board::printBoard()
{
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

Board::~Board()
{
	for (int i = 0; i < height; i++)
	{
		delete map[i];
	}
	delete map;
}