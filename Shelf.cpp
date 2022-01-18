#include "Shelf.h"

bool Shelf::addPublication(Publication& added)
{
	if (this->publications.size() == this->capacity)
	{
		return false;
	}
	this->publications.push_back(&added);
	return true;
}
