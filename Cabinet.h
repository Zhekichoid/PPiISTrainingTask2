#pragma once
#include "Shelf.h"

class Cabinet
{
protected:
	vector <Shelf> shelfs;
	static const int shelfsNumber = 3;
	bool addPublication(shared_ptr<Publication> publication);
	Cabinet(){ }
public:
	vector <Shelf> getShelfs() { return this->shelfs; }
	friend class Librarian;
	friend class Admin;
};