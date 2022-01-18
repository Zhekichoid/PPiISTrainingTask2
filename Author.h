#pragma once
#include <iostream>

using namespace std;

class Author
{
private:
	string name;
	int bornYear;
	int deathYear;
public:
	Author(string name, int born, int death = 2023) :
		name(name), bornYear(born), deathYear(death)
	{}
	string getName() { return this->name; }
	int getBornYear() { return this->bornYear; }
	int getDeathYear() { return this->deathYear; }
};