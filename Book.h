#pragma once
#include "Publication.h"
#include "Author.h"

class Book : public Publication
{
private:
	vector <Author*> authors;
public:
	vector <Author*> getAuthors() { return this->authors; }
};