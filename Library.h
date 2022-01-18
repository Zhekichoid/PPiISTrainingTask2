#pragma once
#include "Cabinet.h"
#include <memory>


class Library
{
private:
	vector <shared_ptr<Cabinet>> cabinets;
	const string name;
	const string address;
	vector <shared_ptr<Publication>> givenPublications; //������ �������� �������
	vector <shared_ptr<Publication>> unsortedPublications;
	Library(string name,string address):
		name(name), address(address)
	{ }
protected:
	//������ ��� ������� ������ � ��������������+������������ 
	vector <shared_ptr<Cabinet>> getCabinets() { return this->cabinets; }

public:

	friend class Admin;
	friend class Librarian;
};