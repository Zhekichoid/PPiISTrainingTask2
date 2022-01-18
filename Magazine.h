#pragma once
#include <map>
#include "Publication.h"

class Magazine : public Publication
{
private:
	string productionMonth;
	map <string, string> themes;
public:
	map <string, string> getThemes() { return this->themes; }
};