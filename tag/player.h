#pragma once
#include <string>
#include "entity.h"
using namespace std;

class Player : public Entity
{
public:
	Player() {};
	~Player() {};

	void setPlayerX(int x) { playerX = x; }
	int getPlayerX() { return playerX; }
	void setPlayerY(int y) { playerY = y; }
	int getPlayerY() { return playerY; }

	void setExp(int e) { exp = e; }
	int getExp() { return exp; }

	void setPlayerName()
	{
		string pn;
		cout << "Enter your name player: ";
		cin >> pn;
		playerName = pn;
	}

	void setPlayerName(string n) { playerName = n; }
	string getPlayerName() { return playerName; }

	void incPlayerExp(int); //This will be called in the combat function and will pass in the enemy expValue
	void setLevel(int l) { level = l; }
	int getLevel() { return level; }

private:
	int playerX, playerY, exp = 0, level = 1;
	string playerName;
};
