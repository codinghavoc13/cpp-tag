#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Item {
public:
	Item() {};
	string getType() { return itemType; };
	void setType(string type) { itemType = type; };
	int getAmt() { return itemAmt; }
	void setAmt(int amt) { itemAmt = amt; }
	void setX(int x) { xValue = x; }
	int getX() { return xValue; }
	void setY(int y) { yValue = y; }
	int getY() { return yValue; }
	void setchestNbr(int n) { chestNbr = n; }
	int getchestNbr() { return chestNbr; }
	Item* start;
	Item* prev;
	Item* next;

private:
	string itemType = "";
	int itemAmt = 0;
	int chestNbr = 0;
	int xValue = 0, yValue = 0;
};