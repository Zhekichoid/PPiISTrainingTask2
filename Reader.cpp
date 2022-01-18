#include "Reader.h"

void Reader::publicationRequest(shared_ptr<Publication> needed, shared_ptr <Librarian> librarian)
{
	auto readerPtr = make_shared<Reader>(this);
	librarian->addRequest(needed, readerPtr);
}

void Reader::goInside(shared_ptr <Library> neededLibrary)
{
	this->currentLibrary = neededLibrary;
}

void Reader::getCabinetsAccess(Admin& admin)
{
	this->currentCabinets = admin.giveCabinetsAccess();
}

void Reader::search(shared_ptr <Librarian> librarian)
{
	if (this->currentPublications.size() == maxPublicationsNumber)
	{
		//exception: there is no slots 
	}
	shared_ptr <ISearch> request;
	int searchType;
	string needed;
	cin >> searchType; //ввод типа поиска
	cin >> needed; //запрос (имя автора/год и тд)
	switch (searchType)
	{
	case 0: //поиск по автору
		request = make_shared<SearchByAuthor>(needed);
	case 1: //по году выпуска
		request = make_shared<SearchByProductionYear>(needed);
	case 2://по году жизни автора
		request = make_shared<SearchByLifeYear>(needed);
	case 3://по теме
		request = make_shared<SearchByTheme>(needed);
	}
	shared_ptr <Publication> result = searchProcessing(request);
	if (result)
	{
		this->publicationRequest(result, librarian);
	}
	else // книга не найдена
}

shared_ptr <Publication> Reader::searchProcessing(shared_ptr <ISearch> request)
{
	shared_ptr<Publication> result;
	for (int i = 0; i < this->currentCabinets.size(); i++)
	{
		vector <Shelf> currentShelfs = currentCabinets[i]->getShelfs();
		for (int j = 0; j < currentShelfs.size(); j++)
		{
			vector <shared_ptr<Publication>> publications = currentShelfs[j].getPublications();
			for (int k = 0; k < publications.size(); k++)
			{
				if (request->search(publications[k]))
				{
					return publications[k];
				}
			}
		}
	}
	return nullptr;
}

void Reader::giveBack(shared_ptr<Publication> given, shared_ptr<Librarian> librarian)
{
	librarian->takePublicationBack(given);
	for (int i = 0; i < this->currentPublications.size(); i++)
	{
		if (given == this->currentPublications[i])
		{
			this->currentPublications.erase(currentPublications.begin() + i);
		}
	}
}


