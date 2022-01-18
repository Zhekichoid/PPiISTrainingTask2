#pragma once
#include "Publication.h"

class Shelf
{
private:
	vector <shared_ptr<Publication>> publications;
	static const int capacity = 7;
public:
	Shelf() {};
	bool addPublication(Publication& added);
	vector <shared_ptr<Publication>> getPublications() { return this->publications; }
};