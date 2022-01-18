#include "Librarian.h"

shared_ptr<Cabinet> Librarian::priorityCheck(shared_ptr<Publication> verifiable)
{
	auto magazineCheck = dynamic_pointer_cast<Magazine>(verifiable);
	auto bookCheck = dynamic_pointer_cast<Book>(verifiable);
	vector<shared_ptr<Cabinet>> cabinets = this->placeOfWork->cabinets;
	if (magazineCheck)
	{
		string title = magazineCheck->getTitle();
		for (int i = 0; i < cabinets.size(); i++)
		{
			auto thematic = dynamic_pointer_cast<OneTitleCabinet>(cabinets[i]);
			if (thematic)
			{
				if (thematic->getTitle() == title)
				{
					return thematic;
				}
			}
		}
	}
	else if (bookCheck)
	{
		vector <Author*> author = bookCheck->getAuthors();
		if (author.size() != 1)
		{
			throw; //больше одного автора
		}
		string authorName = author[0]->getName();
		for (int i = 0; i < cabinets.size(); i++)
		{
			auto thematic = dynamic_pointer_cast<OneAuthorCabinet>(cabinets[i]);
			if (thematic)
				if (thematic->getAuthorName() == authorName)
				{
					return thematic;
				}
		}
	}
	else
		return nullptr;
}

void Librarian::givePublication(shared_ptr<Publication> given)
{
	map <shared_ptr <Publication>, shared_ptr <Reader>> :: iterator it;
	it = this->publicationRequests.find(given);
	if (find(this->publicationRequests.begin(), this->publicationRequests.end(), it->first) != this->publicationRequests.end())
	{
		throw;  //издание уже отдали 
	}
	it->second->currentPublications.push_back(it->first);
	this->placeOfWork->givenPublications.push_back(it->first);
	this->publicationRequests.erase(it);
}

void Librarian::insertPublication(shared_ptr<Publication> inserted)
{
	auto isPriority = this->priorityCheck(inserted);
	if (!isPriority)
	{
		int chooseCabinet;
		vector <shared_ptr<Cabinet>> cabinets = this->placeOfWork->cabinets;
		cin >> chooseCabinet;
		isPriority = cabinets[chooseCabinet];
	}
	isPriority->addPublication(inserted);
}

void Librarian::addRequest(shared_ptr<Publication> added, shared_ptr <Reader> customer)
{
	this->publicationRequests[added] = customer;
}

void Librarian::takePublicationBack(shared_ptr<Publication> returned)
{
	vector <shared_ptr<Publication>> givenPublications = this->placeOfWork->givenPublications;
	for (int i = 0; i < givenPublications.size(); i++)
	{
		if (returned == givenPublications[i])
		{
			givenPublications.erase(givenPublications.begin() + i);
		}
	}
}
