#include "Cabinet.h"

bool Cabinet::addPublication(shared_ptr <Publication> publication)
{
	bool isPlaced = false;
	for (int i = 0; i < this->shelfs.size(); i++)
	{
		if (shelfs[i].addPublication(publication))
		{

		}
	}
	return false;
}
