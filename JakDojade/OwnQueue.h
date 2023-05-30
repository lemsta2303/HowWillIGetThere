#pragma once

class OwnQueue {
private:
	int* data;
	int size;
	int head; // index pierwszej wartosci w kolejce
	int tail; // index pierwszego wolnego miejsca w kolejce
public:
	OwnQueue();
	void enqueue(int value);
	int dequeue();
	int getSize() const;
	void printQueue();
	~OwnQueue();
};