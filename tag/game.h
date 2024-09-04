#pragma once
#include "stdafx.h"
#include "map.h"
#include "sector.h"
#include "treasurechest.h"
#include "inventory.h"
#include "items.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <string>
using namespace std;

int randNum();
int randItemNum();
int randEnemyNum();
int randCombatNum();

class MainGame
{
public:
	~MainGame() {};

	void setMapX(int x) { mapX = x; }
	int getMapX() { return mapX; }
	void setMapY(int y) { mapY = y; }
	int getMapY() { return mapY; }

	void setMapSize();

	int combat(Player*, Enemy*, Inventory*);

	void addsector(GameMap*, int, int);

	void addTreasure(TreasureChest*, GameMap*, int, int);

	void addEnemy(Enemy*, GameMap*, int, int);

	void foundTreasure(Sector*, TreasureChest*, Inventory*, GameMap*);

	bool combatResult(Sector*, Player*, Enemy*, GameMap*, Inventory*);

	void gameSave(MainGame*);
	void inventorySave(Inventory*);
	void treasureChestSave(TreasureChest*);
	void mapSave(GameMap*);
	void playerSave(Player*);
	void enemySave(Enemy*);

	void gameLoad(MainGame*);
	void inventoryLoad(Inventory*);
	void treasureChestLoad(TreasureChest*);
	void mapLoad(GameMap*);
	void playerLoad(Player*);
	void enemyLoad(Enemy*);

	int sectorCount = 0;
	int treasureCount = 0;
	int enemyCount = 0;

	void mainGame(MainGame*, TreasureChest*, Inventory*, GameMap*, Player*, Enemy*);

private:
	int mapX, mapY;
};