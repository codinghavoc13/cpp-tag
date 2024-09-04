#pragma once
#include <string>
#include "entity.h"
using namespace std;

class Enemy : public Entity
{
public:
	Enemy() {};
	//Enemy::~Enemy(){};

	void setEnemyType(string et) { enemyType = et; }
	string getEnemyType() { return enemyType; }

	//void Enemy::setLevel(int);
	int getLevel() { return level; }

	void addEnemy(string, int, int);
	/*This one is for loading enemy from save file*/
	void addEnemy(string, int, int, int, int);

	string randEnemy(int);

	void setX(int x) { xValue = x; }
	int getX() { return xValue; }
	void setY(int y) { yValue = y; }
	int getY() { return yValue; }
	void setexpValue(int eV) { expValue = eV; }
	int getexpValue() { return expValue; }

	void display();

	Enemy* searchEnemy(int, int);

	void deleteEnemy(int, int); //Possible plan later for including string if needing to delete one type of enemy from a multiple enemy cell

	Enemy* prev, * next, * start = nullptr;

private:
	int level = 1;
	int xValue, yValue;
	int expValue;
	string enemyType;
};

