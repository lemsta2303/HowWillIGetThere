#include <iostream>

#include "OwnString.h"

using namespace std;

OwnString::OwnString()
{
	word = new char[0];
	length = 0;
}

char* OwnString::getWord() const
{
	return word;
}

int OwnString::getLength() const
{
	return length;
}

void OwnString::addLetter(char letter)
{
	char* word_tmp;
	word_tmp = word;
	length++;
	word = new char[length];
	for (int i = 0; i < length-1; i++)
	{
		word[i] = word_tmp[i];
	}
	word[length-1] = letter;
	delete[] word_tmp;
}

void OwnString::clearString()
{
	for (int i = 0; i < length; i++)
	{
		word[i] = NULL;
	}
	length = 0;
	word = new char[0];
}

void OwnString::reverseWord()
{
	char* word_tmp;
	word_tmp = new char[length];
	for (int i = 0; i < length; i++)
	{
		word_tmp[i] = word[length - 1 - i];
	}
	this->setString(word_tmp, length);
	delete[] word_tmp;
}

int OwnString::convertStringNumberToInt()
{
	int number = 0;
	int k = 1;
	for (int i = length-1; i >= 0; i--)
	{
		number += (int(word[i]) - '0') * k;
		k *= 10;
	}
	return number;
}

bool OwnString::ifEqualString(OwnString x)
{
	if (length != x.getLength()) return false;
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (word[i] != x.getWord()[i]) return false;
		}
	}
	return true;
}

void OwnString::setString(char* tab, int len)
{
	word = new char[len];
	length = len;
	for (int i = 0; i < len; i++)
	{
		word[i] = tab[i];
	}
}

void OwnString::printString()
{
	for (int i = 0; i < length; i++)
	{
		cout << word[i];
	}
}

OwnString::~OwnString()
{}