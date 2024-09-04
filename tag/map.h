#pragma once
#include "sector.h"
#include "stdafx.h"
using namespace std;

class GameMap
{
public:
	GameMap();

	//void MainGame();
	void setXValue(int);
	int getXValue();

	void setYValue(int);
	int getYValue();

	void setPlayerX(int);
	void setPlayerY(int);

	int getPlayerX();
	int getPlayerY();

	void addSector(int, int);

	void listSector(int, int); //For test purposes only
	void listSectorT(int, int); //For test purposes only
	void listSectorE(int, int); //For test purposes only
	void listSectorStatus();
	void listAllSectorInfo(); //For test purposes only

	void scrollingMap(int, int);
	void centerMap(int, int);

	Sector* searchSector(int, int);

	string getSectorStatus(int, int);
	void setSectorStatus(int, int, string);

	string getSectorEnemy(int, int);
	void setSectorEnemy(int, int, string);

	string getSectorTreasure(int, int);
	void setSectorTreasure(int, int, string);

	void displayCurrLoc();
	void displayPrevLoc();
	void displayLoc(Sector*);

	void setCurrEnemyStat(string enStat) { currLoc->enemy = enStat; };
	void setCurrTreasureStat(string treaStat) { currLoc->treasure = treaStat; }

	Sector* navigation(string, int, int);

	Sector* currLoc = nullptr;
	Sector* prevLoc = nullptr;
private:
	Sector* start = nullptr;
	int xCount = 0;
	int yCount = 0;
	int playerX = 0;
	int playerY = 0;
};