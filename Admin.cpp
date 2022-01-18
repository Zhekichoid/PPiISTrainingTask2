#include "Admin.h"

void Admin::approveAccess(shared_ptr<Reader> approved)
{
	approved->access = true;
}

void Admin::hireLibrarian(shared_ptr<Librarian> hired)
{
	hired->placeOfWork = this->controlledLibrary;
}

void Admin::fireLibrarian(shared_ptr<Librarian> fired)
{
	fired->placeOfWork = nullptr;
}

void Admin::deleteCabinet(shared_ptr<Cabinet> deleted)
{
}

void Admin::createCabinet()
{
	shared_ptr <Cabinet> newCabinet = make_shared<Cabinet>();
	this->controlledLibrary->cabinets.push_back(newCabinet);
}

void Admin::makeThematic(shared_ptr<Cabinet> changeable)
{

}

vector<shared_ptr<Cabinet>> Admin::giveCabinetsAccess()
{
	return this->controlledLibrary->getCabinets();
}
