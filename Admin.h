#pragma once
#include "Human.h"
#include "Librarian.h"
#include "Reader.h"

class Admin: public Human
{
private:
	shared_ptr <Library> controlledLibrary;
	vector <shared_ptr<Publication>> ownBooks;
public:
	Admin(string name) :
		Human(name)
	{}
	
	void approveAccess(shared_ptr <Reader> approved); 

	void hireLibrarian(shared_ptr <Librarian> hired);
	
	void fireLibrarian(shared_ptr <Librarian> fired);
	
	void deleteCabinet(shared_ptr <Cabinet> deleted);
	
	void createCabinet();
	
	void makeThematic(shared_ptr <Cabinet> changeable);
	
	vector <shared_ptr<Cabinet>> giveCabinetsAccess();
	
	void buyPublications(string );
};