#pragma once
#include "stdafx.h"
#include "inventory.h"

void Inventory::addItem(string type, int amt) {
	bool cont = true;
	Item* newItem = new Item();
	newItem->setType(type);
	newItem->setAmt(amt);
	Item* temp = start;
	//Check if the item is already in the inventory
	while (temp != nullptr)
	{
		if (newItem->getType() == temp->getType())
		{
			temp->setAmt(temp->getAmt() + newItem->getAmt());
			cont = false;
		}
		temp = temp->next;
	}
	if (cont == true)
	{
		Item* temp2 = start;
		if (start == nullptr)
		{
			start = newItem;
		}
		else
		{
			while (temp2->next != nullptr)
			{
				temp2 = temp2->next;
			}
			if (temp2->next == nullptr)
			{
				temp2->next = newItem;
				newItem->prev = temp2;
				newItem->next = nullptr;
			}
		}
	}
	cout << "Item " << newItem->getType() << " added to inventory\n";
}

void Inventory::display()
{
	Item* temp = start;
	while (temp != nullptr)
	{
		cout << "Type: " << temp->getType() << " x " << temp->getAmt() << endl;
		temp = temp->next;
	}
}

void Inventory::transferItem(Item* temp)
{
	string t = temp->getType();
	int a = temp->getAmt();
	int x = temp->getX(), y = temp->getY();
	Inventory::addItem(t, a);
};

bool Inventory::checkHealthPotion()
{
	Item* temp = start;
	while (temp != nullptr)
	{
		if (temp->getType() == "healing potion")
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
};

Item* Inventory::search(string s)
{
	Item* temp = start;
	while (temp != nullptr)
	{
		if (temp->getType() == s)
			return temp;
		else temp = temp->next;
	}
}