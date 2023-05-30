#pragma once
#include <iostream>

using namespace std;

template <typename T> 
class OwnVector {
	T* elements;
	int total_storage;
	int size; // ilosc elementow aktualnie w vectorze
public:
	OwnVector();
	int getSize();
	T getElement(int index);
	T* getPointetToElement(int index);
	void push(T t);
	void printVector();
	~OwnVector();
};

template <typename T>
OwnVector<T>::OwnVector()
{
	elements = new T[1];
	total_storage = 1;
	size = 0;
}

template <typename T>
int OwnVector<T>::getSize()
{
	return size;
}

template <typename T>
T OwnVector<T>::getElement(int index)
{
	return elements[index];
}

template <typename T>
T* OwnVector<T>::getPointetToElement(int index)
{
	return &elements[index];
}

template <typename T>
void OwnVector<T>::push(T t)
{
	if (size == total_storage)
	{
		T* tmp = new T[2 * total_storage];
		for (int i = 0; i < total_storage; i++)
		{
			tmp[i] = elements[i];
		}
		delete[] elements;
		total_storage = total_storage * 2;
		elements = tmp;
	}
	elements[size] = t;
	size++;
}

template <typename T>
void OwnVector<T>::printVector()
{
	for (int i = 0; i < size; i++)
	{
		cout << elements[i] << endl;
	}
}

template <typename T>
OwnVector<T>::~OwnVector()
{
	delete[] elements;
}