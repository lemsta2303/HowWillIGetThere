#define NOT_CONNECTED   -1
#define NEW_LANE        10 
#define SPACE           32

#include <iostream>
#include <cstdlib>

#include "Graph.h"

using namespace std;

void Graph::loadBoard()
{
	my_board.loadMap();
	my_board.loadCities();
	createAdjList();
	setAdjacencyList();
	loadFlights();
	addFlightsToList();
	loadAndExecuteQuestions();
}

City Graph::findCityByNameAndReturnIt(OwnString x)
{
	for (int i = 0; i < my_board.getCityCounter(); i++)
	{
		if (my_board.getCityAtPos(i).getName().ifEqualString(x))
		{
			return my_board.getCityAtPos(i);
		}
	}
	return my_board.getCityAtPos(0);
}

void Graph::loadFlights()
{
	cin >> flights_number;
	flights = new Flight[flights_number];
	OwnString distance_string;
	int distance;
	char letter;
	char catchFirstNewLane = getchar();
	int if_first_word = 1;
	int if_second_word = 0;
	int if_third_word = 0;
	for (int i = 0; i < flights_number; i++)
	{
		while (!flights[i].if_setted)
		{
			letter = getchar();
			if (letter == NEW_LANE && flights[i].from.getLength() != 0 && flights[i].to.getLength() != 0)
			{
				flights[i].distance = distance_string.convertStringNumberToInt();
				flights[i].if_setted = 1;
				distance_string.clearString();
				if_first_word = 1;
				if_second_word = 0;
				if_third_word = 0;
			}
			else if (letter == SPACE)
			{
				if (if_first_word)
				{
					if_first_word = 0;
					if_second_word = 1;
				}
				else if (if_second_word)
				{
					if_second_word = 0;
					if_third_word = 1;
				}
			}
			else if (if_first_word == 1)
			{
				flights[i].from.addLetter(letter);
			}
			else if (if_second_word == 1)
			{
				flights[i].to.addLetter(letter);
			}
			else if (if_third_word == 1)
			{
				distance_string.addLetter(letter);
			}
		}
	}
}

void Graph::loadAndExecuteQuestions()
{
	OwnString from;
	int from_index;
	OwnString to;
	int to_index;
	bool if_print_cities;
	OwnString if_print_cities_stirng;
	bool if_command_done = 0;
	char letter;
	int questions_number;
	cin >> questions_number;
	char catchFirstNewLane = getchar();
	int if_first_word = 1;
	int if_second_word = 0;
	int if_third_word = 0;
	for (int i = 0; i < questions_number; i++)
	{
		while (!if_command_done)
		{
			letter = getchar();
			if (letter == NEW_LANE && from.getLength() != 0 && to.getLength() != 0)
			{
				if_print_cities = if_print_cities_stirng.convertStringNumberToInt();
				if_command_done = true;
				from_index = findCityByNameAndReturnIt(from).getIndex();
				to_index = findCityByNameAndReturnIt(to).getIndex();
				dijkstra(from_index, to_index, if_print_cities);
				from.clearString();
				to.clearString();
				if_print_cities_stirng.clearString();
				if_first_word = 1;
				if_second_word = 0;
				if_third_word = 0;
			}
			else if (letter == SPACE)
			{
				if (if_first_word)
				{
					if_first_word = 0;
					if_second_word = 1;
				}
				else if (if_second_word)
				{
					if_second_word = 0;
					if_third_word = 1;
				}
			}
			else if (if_first_word == 1)
			{
				from.addLetter(letter);
			}
			else if (if_second_word == 1)
			{
				to.addLetter(letter);
			}
			else if (if_third_word == 1)
			{
				if_print_cities_stirng.addLetter(letter);
			}
		}
		if_command_done = false;
	}
}

void Graph::createAdjList()
{
	adj_list = new OwnVector<Node>[my_board.getCityCounter()];
}

int Graph::findShortestRoadBetweenTwoCities(City first, City second)
{
	bool** check = new bool* [my_board.getHeight()];
	for (int i = 0; i < my_board.getHeight(); i++)
	{
		check[i] = new bool[my_board.getWidth()];
	}
	for (int i = 0; i < my_board.getHeight(); i++)
	{
		for (int j = 0; j < my_board.getWidth(); j++)
		{
			check[i][j] = false;
		}
	}
	int starting_x = first.getXPosition();
	int starting_y = first.getYPosition();
	OwnQueue x_queue;
	OwnQueue y_queue;
	int move_counter = 0;
	int fieldsLeft = 1;
	int fieldsNext = 0;
	x_queue.enqueue(starting_x);
	y_queue.enqueue(starting_y);
	check[starting_x][starting_y] = true;
	int x, y;
	bool if_end = false;
	while (x_queue.getSize() > 0)
	{
		x = x_queue.dequeue();
		y = y_queue.dequeue();
		if (x == second.getXPosition() && y == second.getYPosition()) if_end = true;
		int m = 0, n = 0;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if ((j == 0 || i == 0) && !(j == 0 && i == 0))
				{
					m = x + i;
					n = y + j;
					if (m >= 0 && m < my_board.getHeight() && n >= 0 && n < my_board.getWidth() && check[m][n] == false)
					{
						if (my_board.getMapField(m, n) == '#')
						{
							x_queue.enqueue(m);
							y_queue.enqueue(n);
							check[m][n] = true;
							fieldsNext++;
						}
						else if (my_board.getMapField(m, n) == '*')
						{
							if (m == second.getXPosition() && n == second.getYPosition()) // waruenk wykonuje sie tylko gdy odnalezlismy szukane miasto
							{															   // nie wykonuje sie gdy miasta sa rozgraniczane innym miastem
								x_queue.enqueue(m);
								y_queue.enqueue(n);
								check[m][n] = true;
								fieldsNext++;
							}
						}
					}
				}
			}
		}
		if (if_end)
		{
			for (int i = 0; i < my_board.getHeight(); i++)
			{
				delete[] check[i];
			}
			delete[] check;
			return move_counter;
		}
		fieldsLeft--;
		if (fieldsLeft == 0)
		{
			fieldsLeft = fieldsNext;
			fieldsNext = 0;
			move_counter++;
		}
	}
	for (int i = 0; i < my_board.getHeight(); i++)
	{
		delete[] check[i];
	}
	delete[] check;
	return NOT_CONNECTED;
}

void Graph::setAdjacencyList()
{
	Node first;
	Node second;
	int distance = -1;
	for (int i = 0; i < my_board.getCityCounter(); i++)
	{
		first.node_city = my_board.getCityAtPos(i);
		for (int j = 0; j < my_board.getCityCounter(); j++)
		{
			if (i != j)
			{
				second.node_city = my_board.getCityAtPos(j);
				distance = findShortestRoadBetweenTwoCities(first.node_city, second.node_city);
				if (distance != -1)
				{
					second.distance = distance;
					adj_list[first.node_city.getIndex()].push(second);
				}
			}
		}
	}
}

void Graph::addFlightsToList()
{
	int if_flight_setted = 0;
	Node city_to_add;
	for (int i = 0; i < flights_number; i++)
	{
		if_flight_setted = 0;
		for (int j = 0; j < my_board.getCityCounter() && !if_flight_setted; j++)
		{
			for (int k = 0; k < adj_list[j].getSize() && !if_flight_setted; k++)
			{
				if ((my_board.getCityAtPos(j).getName().ifEqualString(flights[i].from)) && (adj_list[j].getElement(k).node_city.getName().ifEqualString(flights[i].to)))
				{
					if (adj_list[j].getPointetToElement(k)->distance > flights[i].distance)
					{
						adj_list[j].getPointetToElement(k)->distance = flights[i].distance;
						if_flight_setted = 1;
					}
				}
			}
		}
		if (!if_flight_setted)
		{
			city_to_add.node_city = findCityByNameAndReturnIt(flights[i].to);
			city_to_add.distance = flights[i].distance;
			adj_list[findCityByNameAndReturnIt(flights[i].from).getIndex()].push(city_to_add);
		}
	}
}

void Graph::dijkstra(int start_index, int finish_index, bool if_print_prev_cities)
{
	int* visited = new int[my_board.getCityCounter()];
	int* min_distance = new int[my_board.getCityCounter()];
	int* prev = new int[my_board.getCityCounter()];
	for (int i = 0; i < my_board.getCityCounter(); i++)
	{
		visited[i] = 0;
		min_distance[i] = 999999;
		prev[i] = -1;
	}
	min_distance[start_index] = 0; // dystans dla poczatkowego
	int current = start_index;
	int tmp_min_distance = 999999;
	while (current != finish_index)
	{
		for (int i = 0; i < adj_list[current].getSize(); i++)
		{
			if (visited[adj_list[current].getElement(i).node_city.getIndex()] == 0)
			{
				if (min_distance[adj_list[current].getElement(i).node_city.getIndex()] > min_distance[current] + adj_list[current].getElement(i).distance) // sprawdzanie czy nowy najmniejszy dystans
				{
					min_distance[adj_list[current].getElement(i).node_city.getIndex()] = min_distance[current] + adj_list[current].getElement(i).distance;
					prev[adj_list[current].getElement(i).node_city.getIndex()] = current; // ustawianie poprzednio odwiedzonego miasta
				}
			}
		}
		visited[current] = 1;
		tmp_min_distance = 999999;
		for (int i = 0; i < my_board.getCityCounter(); i++)
		{
			if (min_distance[i] < tmp_min_distance && visited[i] == 0 && i!=current)
			{
				tmp_min_distance = min_distance[i];
				current = i;
			}
		}
	}
	cout << min_distance[current];
	int index = 0;
	OwnVector<OwnString> cities_to_print;
	if (if_print_prev_cities)
	{
		cout << " ";
		current = prev[current];
		if (current >= 0)
		{
			while (current != start_index)
			{
				cities_to_print.push(my_board.getCityAtPos(current).getName());
				current = prev[current];
			}

			for (int i = cities_to_print.getSize() - 1; i >= 0; i--)
			{
				cities_to_print.getElement(i).printString();
				cout << " ";
			}
		}
	}
	cout << endl;
	delete[] visited;
	delete[] min_distance;
	delete[] prev;
}

void Graph::printAdjacencyList()
{
	for (int i = 0; i < my_board.getCityCounter(); i++)
	{
		my_board.getCityAtPos(i).printCity();
		cout << " --> ";
		for (int j = 0; j < adj_list[i].getSize(); j++)
		{
			adj_list[i].getElement(j).node_city.printCityName();
			cout << "/DISTANCE: " << adj_list[i].getElement(j).distance;
			cout << " -->";
		}
		cout << endl;
	}
}

void Graph::printFlights()
{
	for (int i = 0; i < flights_number; i++)
	{
		cout << i + 1 << ". from ";
		flights[i].from.printString();
		cout << " to ";
		flights[i].to.printString();
		cout << "(Distance: ";
		cout << flights[i].distance;
		cout << ")" << endl;
	}
}