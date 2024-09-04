#include "stdafx.h"
#include "sector.h"
#include "map.h"
#include "player.h"
#include <iostream>

int randNum();

GameMap::GameMap() {};

void GameMap::listSectorStatus()
{
	int x = getXValue();
	int y = getYValue();
	for (int col = (x - 1); col >= 0; col--)
	{
		for (int row = 0; row < y; row++)
		{
			cout << "+---+";
		}
		cout << endl;
		for (int row1 = 0; row1 < y; ++row1)
		{
			cout << "|" << GameMap::getSectorStatus(row1, col) << "|";
		}
		cout << endl;
		for (int row2 = 0; row2 < y; row2++)
		{
			cout << "+---+";
		}
		cout << endl;
	}
	system("pause");
}

void GameMap::setXValue(int x) { xCount = x; };

int GameMap::getXValue() { return xCount; };

void GameMap::setYValue(int y) { yCount = y; };

int GameMap::getYValue() { return yCount; };

void GameMap::setPlayerX(int x) { playerX = x; };

void GameMap::setPlayerY(int y) { playerY = y; };

int GameMap::getPlayerX() { return playerX; };

int GameMap::getPlayerY() { return playerY; };

Sector* GameMap::searchSector(int x, int y) //I get a warning saying that not all control paths return a value. Will this cause issues?
{
	Sector* temp = start;
	while (temp != nullptr)
	{
		if (temp->x == x && temp->y == y)
			return temp;
		else
			temp = temp->next;
	}
};

string GameMap::getSectorStatus(int x, int y)
{
	Sector* temp = searchSector(x, y);
	if (temp->status == "new")
		return "   ";
	else if (temp->status == "clear")
		return " C ";
	else if (temp->status == "start")
		return " S ";
	else
		return " X ";
};

void GameMap::setSectorStatus(int x, int y, string newStat)
{
	Sector* temp = searchSector(x, y);
	temp->status = newStat;
}

void GameMap::listAllSectorInfo()
{
	Sector* temp = start;
	while (temp->next != nullptr)
	{
		cout << "Sector: " << temp->x << "," << temp->y << "| Status: " << temp->status << endl;
		temp = temp->next;
	}
};

void GameMap::displayCurrLoc()
{
	Sector* temp = currLoc;
	cout << "Current location: " << temp->x << "," << temp->y << endl;
}

void GameMap::displayPrevLoc()
{
	Sector* temp = prevLoc;
	cout << "Previous location: " << temp->x << "," << temp->y << endl;
}

void GameMap::displayLoc(Sector* tmp)
{
	cout << "Location: " << tmp->x << "," << tmp->y << endl;
}


string GameMap::getSectorEnemy(int x, int y)
{
	Sector* temp = searchSector(x, y);
	if (temp->enemy == "none")
		return "   ";
	else if (temp->enemy == "present")
		return " P ";
	else if (temp->enemy == "destroyed")
		return " D ";
	else if (temp->enemy == "yes")
		return " Y ";
	else
		return " X ";
};
void GameMap::setSectorEnemy(int x, int y, string newEnemy)
{
	Sector* temp = searchSector(x, y);
	temp->enemy = newEnemy;
};

string GameMap::getSectorTreasure(int x, int y)
{
	Sector* temp = searchSector(x, y);
	if (temp->treasure == "none")
		return "   ";
	else if (temp->treasure == "present")
		return " P ";
	else if (temp->treasure == "unclaimed")
		return " U ";
	else if (temp->treasure == "claimed")
		return " C ";
	else
		return " X ";
};
void GameMap::setSectorTreasure(int x, int y, string newTreasure)
{
	Sector* temp = searchSector(x, y);
	temp->treasure = newTreasure;
};