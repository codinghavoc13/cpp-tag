#pragma once
#include "stdafx.h"
#include "items.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class TreasureChest : public Item
{
public:
	TreasureChest() { };
	~TreasureChest() {};

	void addItem(string, int, int, int);

	void display();
	void display(int, int);

	string randItem(int);

	void transferItem(Item*); //new code

	Item* searchItems(int, int); //new code

	void deleteItem(string, int, int); //new code
	void deleteItem(int, int);
	Item* start = nullptr;

private:

};