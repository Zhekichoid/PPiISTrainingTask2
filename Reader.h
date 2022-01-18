#pragma once
#include "Human.h"
#include "Search.h"
#include "Admin.h"

class Reader : public Human
{
private:
	bool access;
	shared_ptr <Library> currentLibrary;
	vector <shared_ptr<Cabinet>> currentCabinets;
	static const int maxPublicationsNumber = 10;
	void publicationRequest(shared_ptr<Publication> needed, shared_ptr <Librarian> librarian);
	vector <shared_ptr<Publication>> currentPublications;
public:
	Reader(string name) : 
		Human(name)
	{
		access = false;
	}
	
	void goInside(shared_ptr <Library> neededLibrary); 
	
	void getCabinetsAccess(Admin& admin);
	
	void search(shared_ptr <Librarian> librarian);
	
	shared_ptr <Publication> searchProcessing(shared_ptr <ISearch> request);
	
	void giveBack(shared_ptr <Publication> given, shared_ptr<Librarian> librarian);
	
	friend class Librarian;
	friend class Admin;
};