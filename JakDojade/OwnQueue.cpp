#include <iostream>

#include "OwnQueue.h"

using namespace std;

OwnQueue::OwnQueue()
{
	size = 0;
	head = 0;
	tail = 0;
	data = new int;
}

void OwnQueue::enqueue(int value)
{
	size++;
	int* data_tmp = new int[size];
	for (int i = head; i < tail; i++)
	{
		data_tmp[i] = data[i];
	}
	data_tmp[tail] = value;
	tail++;
	data = data_tmp;
}

int OwnQueue::dequeue()
{
	int dequed_number = data[head];
	for (int i = 0; i < tail - 1; i++)
	{
		data[i] = data[i + 1];
	}
	tail--;
	size--;
	return dequed_number;
}

int OwnQueue::getSize() const
{
	return size;
}

void OwnQueue::printQueue()
{
	for (int i = head; i < tail; i++)
	{
		cout << data[i] << " ";
	}
}

OwnQueue::~OwnQueue()
{
	delete[] data;
}