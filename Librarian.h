#pragma once
#include "Human.h"
#include "Reader.h"
#include <algorithm>
#include "OneTitleCabinet.h"
#include "OneAuthorCabinet.h"

class Librarian : public Human
{
private:
	shared_ptr <Library> placeOfWork;
	map <shared_ptr <Publication>, shared_ptr <Reader>> publicationRequests;
	shared_ptr<Cabinet> priorityCheck(shared_ptr<Publication> verifiable);
public:
	Librarian(string name) :
		Human(name)
	{}
	
	void givePublication(shared_ptr<Publication> given);
	
	void insertPublication(shared_ptr<Publication> inserted);
	
	void addRequest(shared_ptr <Publication> added, shared_ptr <Reader> customer);
	
	void takePublicationBack(shared_ptr <Publication> returned);
	
	friend class Admin;

};