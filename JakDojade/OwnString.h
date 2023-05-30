#pragma once

class OwnString {
private:
	char* word;
	int length;
public:
	OwnString();
	char* getWord() const;
	int getLength() const;
	void addLetter(char letter);
	void clearString();
	void reverseWord();
	int convertStringNumberToInt();
	bool ifEqualString(OwnString x);
	void setString(char* tab, int len);
	void printString();
	~OwnString();

};

