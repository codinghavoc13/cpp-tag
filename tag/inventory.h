#pragma once
#include "stdafx.h"
#include "items.h"
#include <string>
#include <iostream>
using namespace std;

class Inventory //: public Item
{
public:
	~Inventory() {};
	Inventory() {};

	void addItem(string, int);

	void display();

	void transferItem(Item*);

	bool checkHealthPotion();

	Item* search(string);

	Item* start = nullptr;

private:

};