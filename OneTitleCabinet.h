#pragma once
#include "Cabinet.h"

class OneTitleCabinet : public Cabinet
{
private:
	string magazineTitle;
public:
	OneTitleCabinet(string title): 
		Cabinet(), magazineTitle(title)
	{}
	string getTitle() { return this->magazineTitle; }
};