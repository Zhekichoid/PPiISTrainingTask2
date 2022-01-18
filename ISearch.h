#pragma once
#include <iostream>
#include "Publication.h"
#include "Book.h"
#include "Magazine.h"

class ISearch
{
public:
	virtual bool search(shared_ptr <Publication> publication) = 0;
};

class SearchByAuthor : public ISearch
{
private:
	string authorName;
public:
	SearchByAuthor(string name): authorName(name) { }
	bool search(shared_ptr <Publication> publication)
	{
		auto ptrBook = dynamic_pointer_cast<Book>(publication);
		if (ptrBook)
		{
			vector <Author*> authors = ptrBook->getAuthors();
			for (int i = 0; i < authors.size(); i++)
			{
				if (this->authorName == authors[i]->getName())
				{
					return true;
				}
			}
		}
		return false;
	}
};

class SearchByProductionYear : public ISearch
{
private:
	string prodYear;
public:
	SearchByProductionYear(string year): prodYear(year) { }
	bool search(shared_ptr <Publication> publication)
	{
		return (publication->getProductionYear() == this->prodYear);
	}
};

class SearchByLifeYear : public ISearch
{
private:
	int lifeYear;
public:
	SearchByLifeYear(int lifeYear): lifeYear(lifeYear) { }
	bool search(shared_ptr <Publication> publication)
	{
		auto ptrBook = dynamic_pointer_cast<Book>(publication);
		if (ptrBook)
		{
			vector <Author*> authors = ptrBook->getAuthors();
			for (int i = 0; i < authors.size(); i++)
			{
				if (this->lifeYear >= authors[i]->getBornYear() && this->lifeYear <= authors[i]->getDeathYear())
				{
					return true;
				}
			}
		}
		return false;
	}
};

class SearchByTheme : public ISearch
{
private:
	string theme;
public:
	SearchByTheme(string theme) : theme(theme) { }

	bool search(shared_ptr <Publication> publication)
	{
		auto ptrMagazine = dynamic_pointer_cast<Magazine>(publication);
		if (ptrMagazine)
		{
			map <string, string> themes = ptrMagazine->getThemes();
			map <string, string> ::iterator it = themes.begin();
			while (it != themes.end())
			{
				if (this->theme == it->first)
				{
					return true;
				}
				it++;
			}
			return false;
		}
	}
};