#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Publication
{
protected:
	string title;
	string publisherName;
	string productionYear;
	vector <string> text;
public:
	string getTitle() { return this->title; }
	string getPublisherName() { return this->publisherName; }
	string getProductionYear() { return this->productionYear; }
	virtual ~Publication() = default;
};