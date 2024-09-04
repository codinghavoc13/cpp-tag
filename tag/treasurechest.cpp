#pragma once
#include "stdafx.h"
#include "treasurechest.h"

void TreasureChest::addItem(string type, int x, int y, int n) {
	Item* newItem = new Item();
	newItem->setType(type);
	if (type == "arrow")
		newItem->setAmt(15);
	else if (type == "gold")
		newItem->setAmt(50);
	else if (type == "healing potion")
		newItem->setAmt(3);
	else
		newItem->setAmt(1);
	newItem->setX(x);
	newItem->setY(y);
	newItem->setchestNbr(n);
	Item* temp = start;
	if (start == nullptr)
	{
		start = newItem;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			temp->next = newItem;
			newItem->prev = temp;
			newItem->next = nullptr;
		}
	}
}

void TreasureChest::display()
{
	Item* temp = start;
	while (temp != nullptr)
	{
		if (temp->getchestNbr() >= 0)
		{
			//cout << "Chest: (" << getX() << "," << getY() << ")" << endl; 
			cout << "Chest: " << temp->getchestNbr() << ": (" << temp->getX() << "," << temp->getY() << ")" << endl;
			cout << " Type: " << temp->getType() << " x " << temp->getAmt() << endl;
		}

		temp = temp->next;
		//system("pause");
	}
}

void TreasureChest::display(int x, int y)
{
	Item* temp = start;
	while ((temp != nullptr) && (temp->getchestNbr() >= 0))
	{
		if ((temp->getX() == x) && (temp->getY() == y))
		{
			cout << "Chest: " << temp->getchestNbr() << ": (" << temp->getX() << "," << temp->getY() << ")" << endl;
			cout << " Type: " << temp->getType() << " x " << temp->getAmt() << endl;
		}
		temp = temp->next;
	}
}

string TreasureChest::randItem(int r)
{
	switch (r)
	{
	case 1:
		return "sword";
		break;
	case 2:
		return "bow";
		break;
	case 3:
		return "arrow";
		break;
	case 4:
		return "shield";
		break;
	case 5:
		return "healing potion";
		break;
	case 6:
		return "gold";
		break;
	default:
		break;
	}
}

void TreasureChest::transferItem(Item* temp)
{
	string t = temp->getType();
	int a = temp->getAmt();
	int x = temp->getX();
	int y = temp->getY();
	addItem(t, x, y, a);
}

Item* TreasureChest::searchItems(int x, int y)
{
	Item* temp = start;
	while (temp != nullptr)
	{
		if ((temp->getX() == x) && (temp->getY() == y))
			return temp;
		else
			temp = temp->next;
	}
}

void TreasureChest::deleteItem(string t, int x, int y)
{
	Item* temp;
	if (t == start->getType())
	{
		temp = start->next;
		temp->prev = nullptr;
		temp = start;
		start = start->next;
		delete temp;
	}
	else
	{
		temp = searchItems(x, y);
		if (temp->next == nullptr)
		{
			temp = temp->next;
			delete temp;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
}

void TreasureChest::deleteItem(int x, int y)
{
	Item* temp;
	if ((start->getX() == x) && (start->getY() == y))
	{
		temp = start->next;
		temp->prev = nullptr;
		temp = start;
		start = start->next;
		delete temp;
	}
	else
	{
		temp = searchItems(x, y);
		if (temp->next == nullptr)
		{
			temp->prev->next = nullptr;
			delete temp;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	cout << "Item deleted\n";
}