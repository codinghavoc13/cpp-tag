#pragma once
#include "stdafx.h"
#include "enemy.h"

void Enemy::addEnemy(string type, int x, int y) {
	Enemy* newEnemy = new Enemy();
	newEnemy->setEnemyType(type);
	if (type == "goblin")
	{
		//newEnemy->setDmgMult(0.75);
		//newEnemy->incHealth(150);
	}
	if (type == "troll")
	{
		//newEnemy->setDmgMult(1.5);
		//newEnemy->incHealth(125);
	}
	if (type == "orc")
	{
		//newEnemy->setHealth(175);
	}

	newEnemy->setX(x);
	newEnemy->setY(y);
	newEnemy->setexpValue(15);
	Enemy* temp = start;
	if (start == nullptr)
	{
		start = newEnemy;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			temp->next = newEnemy;
			newEnemy->prev = temp;
			newEnemy->next = nullptr;
		}
	}
}

void Enemy::addEnemy(string type, int x, int y, int l, int eV) {
	Enemy* newEnemy = new Enemy();
	newEnemy->setEnemyType(type);
	/*if (type == "goblin")
	{
	newEnemy->setDmgMult(0.75);
	newEnemy->incHealth(150);
	}
	if (type == "troll")
	{
	newEnemy->setDmgMult(1.5);
	newEnemy->incHealth(125);
	}
	if (type == "orc")
	{
	newEnemy->setHealth(175);
	}*/

	newEnemy->setX(x);
	newEnemy->setY(y);
	//newEnemy->setLevel(l);
	newEnemy->setexpValue(eV);
	Enemy* temp = start;
	if (start == nullptr)
	{
		start = newEnemy;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			temp->next = newEnemy;
			newEnemy->prev = temp;
			newEnemy->next = nullptr;
		}
	}
}

string Enemy::randEnemy(int r)
{
	switch (r)
	{
	case 1:
		return "goblin";
		break;
	case 2:
		return "troll";
		break;
	case 3:
		return "orc";
		break;
	case 4:
		return "bandit";
		break;
	case 5:
		return "rogue wizard";
		break;
	default:
		break;
	}
}

void Enemy::display()
{
	Enemy* temp = start;
	while (temp != nullptr)
	{
		if (temp->getEnemyType() != "ispep")
		{
			//cout << "Chest: (" << getX() << "," << getY() << ")" << endl; 
			cout << "Enemy Type: " << temp->getEnemyType() << "\nDamage: " << temp->getWeaponDmg() << "\n";
		}
		temp = temp->next;
		//system("pause");
	}
}

Enemy* Enemy::searchEnemy(int x, int y)
{
	Enemy* temp = start;
	while (temp != nullptr)
	{
		if ((temp->getX() == x) && temp->getY() == y)
			return temp;
		else
			temp = temp->next;
	}
};

void Enemy::deleteEnemy(int x, int y)
{
	Enemy* temp;
	if ((x == start->xValue) && (y == start->yValue))
	{
		temp = start->next;
		temp->prev = nullptr;
		temp = start;
		start = start->next;
		delete temp;
	}
	else
	{
		temp = searchEnemy(x, y);
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
	cout << "Enemy deleted\n";
};