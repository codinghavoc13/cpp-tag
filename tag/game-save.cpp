#include "stdafx.h"
#include "game.h"
#include <fstream>

void MainGame::gameSave(MainGame* tempObj)
{
	ofstream output("mainGameSave.txt");
	output << tempObj->mapX << tempObj->mapY;
	output.close();
};

void MainGame::gameLoad(MainGame* tempObj)
{
	int x, y;
	ifstream input;
	input.open("mainGameSave.txt");
	if (input.fail())
	{
		cout << "Something went wrong\n";
	}
	while (input >> x >> y)
	{
		tempObj->setMapX(x);
		tempObj->setMapY(y);
	}
};

void MainGame::playerSave(Player* tempObj)
{
	ofstream output("playerSave.txt");
	output << tempObj->getPlayerName() << tempObj->getPlayerX() << tempObj->getPlayerY()
		<< tempObj->getLevel() << tempObj->getExp() << endl;
	output.close();
};

void MainGame::playerLoad(Player* tempObj)
{
	string n; //name
	int x, y, /*l,*/ e; //x and y coordinates, level, and experience
	ifstream input;
	if (input.fail())
	{
		cout << "Something went wrong\n";
	}
	while (input >> n >> x >> y /*>> l*/ >> e)
	{
		tempObj->setPlayerName(n);
		tempObj->setPlayerX(x);
		tempObj->setPlayerY(y);
		//tempObj->setLevel(l);
		tempObj->setExp(e);
	}
};

void MainGame::inventorySave(Inventory* tempObj)
{
	Item* tempItem = tempObj->start;
	ofstream output("inventorySave.txt");
	while (tempItem != nullptr)
	{
		output << tempItem->getType() << " " << tempItem->getAmt() << endl;
		tempItem = tempItem->next;
	}
	output.close();
};

void MainGame::inventoryLoad(Inventory* tempObj)
{
	//Code will be similar to the test code, pulling a set of data and
	//throwing it into an add function
};

void MainGame::treasureChestSave(TreasureChest* tempObj)
{
	Item* tempItem = tempObj->start;
	ofstream output("treasureChestSave.txt");
	while (tempItem != nullptr)
	{
		output << tempItem->getType() << " " << tempItem->getAmt() << " " << tempItem->getX()
			<< " " << tempItem->getY() << endl;
		tempItem = tempItem->next;
	}
	output.close();
};

void MainGame::treasureChestLoad(TreasureChest* tempObj)
{
	//Code will be similar to the test code, pulling a set of data and
	//throwing it into an add function
};

void MainGame::mapSave(GameMap* tempObj)
{
	//Code will be similar to treasureChest and Inventory save, switch
	//out Item for Sector
};

void MainGame::mapLoad(GameMap* tempObj)
{
	//Code will be similar to the test code, pulling a set of data and
	//throwing it into an add function
};

void MainGame::enemySave(Enemy* tempObj)
{
	//add expValue
	ofstream output("enemySave.txt");
	while (tempObj != nullptr)
	{
		output << tempObj->getEnemyType() << tempObj->getX() << tempObj->getY()
			<< /*tempObj->getLevel() <<*/ endl;
		tempObj = tempObj->next;
	}
	output.close();
};

void MainGame::enemyLoad(Enemy* tempObj)
{
	//int l;
	//add expValue
	int x, y;
	string t;
	ifstream input;
	input.open("enemySave.txt");
	if (input.fail())
	{
		cout << "Something went wrong\n";
	}
	while (input >> t >> x >> y /*>> l*/)
	{
		tempObj->addEnemy(t, x, y/*, l*/);

	}
};

/*
void Object::upload()
{
	Object *temp = start;
	ofstream output("testfile.txt");
	while (temp != nullptr)
	{
		output << temp->alpha << "\n" << temp->name << endl;
		temp = temp->next;
	}
	output.close();
}

void Object::read(Object *tempObj)
{
	int a = 0;
	string n = "";
	ifstream input;
	input.open("testfile.txt");
	if (input.fail())
	{
		cout << "Something went wrong\n";
	}
	while (input >> a >> n)
	{
		tempObj->addObject(a, n);
	}
}
*/