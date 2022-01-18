#pragma once
#include "Cabinet.h"

class OneAuthorCabinet : public Cabinet
{
private:
	string authorName;
public:
	OneAuthorCabinet(string name) :
		Cabinet(), authorName(name)
	{ }
	string getAuthorName() { return this->authorName; }
};