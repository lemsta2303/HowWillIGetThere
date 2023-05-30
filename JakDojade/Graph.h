#pragma once

#include <iostream>

#include "AdjacencyListNode.h"
#include "Board.h"
#include "FilghtStruct.h"

using namespace std;

class Graph {
private:
	OwnVector<Node>* adj_list;
	Board my_board;
	Flight* flights;
	int flights_number;
public:
	void loadBoard();
	City findCityByNameAndReturnIt(OwnString x);
	void loadFlights();
	void createAdjList();
	int findShortestRoadBetweenTwoCities(City first, City second);
	void setAdjacencyList();
	void addFlightsToList();
	void dijkstra(int start_index, int finish_index, bool if_print_prev_cities);
	void loadAndExecuteQuestions();
	void printAdjacencyList();
	void printFlights();
};