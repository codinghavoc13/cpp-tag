#include "stdafx.h"
#include "game.h"

bool MainGame::combatResult(Sector* tempNew, Player* tempPl, Enemy* tempEn, GameMap* tempMap, Inventory* tempI)
{
	bool tempWF;
	cout << "FIGHT!!!\n";
	tempWF = false;
	Enemy* tempE;
	int result;
	tempE = tempEn->searchEnemy(tempNew->x, tempNew->y);
	result = MainGame::combat(tempPl, tempE, tempI);
	if (result == 1) //if the player wins combat, set the temp sector to the new location
	{
		tempWF = true;
		tempEn->deleteEnemy(tempNew->x, tempNew->y);
		enemyCount--;
		tempNew->enemy = "clear";
	}
	else //if the player loses combat, set temp to the current location, which hasn't moved
		tempWF = false;
	return tempWF;
}

/*
* The sector has been cleared of any enemy, if there were any there to begin with, moving any treasure to the inventory
*/
void MainGame::foundTreasure(Sector* tempNew, TreasureChest* tempChest, Inventory* tempInven, GameMap* tempMap)
{
	cout << "Treasure found in (" << tempNew->x << "," << tempNew->y << ")!\n";
	tempChest->display(tempNew->x, tempNew->y);
	tempInven->transferItem(tempChest->searchItems(tempNew->x, tempNew->y));
	tempChest->deleteItem(tempNew->x, tempNew->y);
	tempInven->display();
	if (tempNew->status != "start")
	{
		tempMap->setCurrTreasureStat("clear");
	}
	tempNew->treasure = "claimed";
	treasureCount--;
	cout << "Sector has no more treasure\n";
}

/*
* Get the desired size of the map from the user
*/
void MainGame::setMapSize()
{
	int enterX, enterY;
	cout << "Set the width of the map: ";
	cin >> enterX;
	setMapX(enterX);
	cout << "Set the height of the map: ";
	cin >> enterY;
	setMapY(enterY);
}

int MainGame::combat(Player* tempPlayer, Enemy* tempEnemy, Inventory* tempInv)
{
	Item* potionTemp;
	int combatNum = randCombatNum();
	char retreat = 'n', drink;
	bool potionCheck;
	//Example: weapon damage = 10; player level 5
	//10 * (5.0 + (5.0/10) -> 10 * (5.0 + 0.5) -> 10 * 5.5 -> 55
	double playerDmg = (tempPlayer->getWeaponDmg() * ((double)tempPlayer->getLevel() + ((double)tempPlayer->getLevel() / 10)));
	while ((tempPlayer->getHealth() > 0) && (tempEnemy->getHealth() > 0))
	{

		if (combatNum % 2 == 1)
		{
			cout << "you hit for " << (tempPlayer->getWeaponDmg() * ((double)tempPlayer->getLevel() + ((double)tempPlayer->getLevel() / 10))) << endl;
			tempEnemy->decHealth(playerDmg);
			//cout << "1-Enemy Health: " << tempEnemy->getHealth() << endl;
			if (tempEnemy->getHealth() <= 0)
				break;
			tempPlayer->decHealth((tempEnemy->getWeaponDmg()));
			//cout << "1-Player Health: " << tempPlayer->getHealth() << endl;
			if (tempPlayer->getHealth() <= tempEnemy->getWeaponDmg())
			{
				potionCheck = tempInv->checkHealthPotion();
				if (potionCheck == true)
				{
					cout << "The enemy can kill you in one more stroke! Do you want to drink a health potion?\n";
					cin >> drink;
					if (drink == 'y')
					{
						potionTemp = tempInv->search("healing potion");
						potionTemp->setAmt(potionTemp->getAmt() - 1);
						tempPlayer->incHealth(100);
					}
				}
				if (potionCheck == false)
				{
					cout << "The enemy can kill you in one more stroke! You are about to die!\n";
					cout << "Do you want to retreat? y/n \n";
					cin >> retreat;
					if (retreat == 'y')
						break;
				}
			}
		}
		else
		{
			tempPlayer->decHealth((tempEnemy->getWeaponDmg()));
			//cout << "2-Player Health: " << tempPlayer->getHealth() << endl;
			if (tempPlayer->getHealth() <= tempEnemy->getWeaponDmg())
			{
				potionCheck = tempInv->checkHealthPotion();
				if (potionCheck == true)
				{
					cout << "The enemy can kill you in one more stroke! Do you want to drink a health potion?\n";
					cin >> drink;
					if (drink == 'y')
					{
						potionTemp = tempInv->search("healing potion");
						potionTemp->setAmt(potionTemp->getAmt() - 1);
						tempPlayer->incHealth(100);
					}
				}
				if (potionCheck == false)
				{
					cout << "The enemy can kill you in one more stroke! You are about to die!\n";
					cout << "Do you want to retreat? y/n \n";
					cin >> retreat;
					if (retreat == 'y')
						break;
				}
			}
			if (tempPlayer->getHealth() <= 0)
				break;
			cout << "you hit for " << (tempPlayer->getWeaponDmg() * ((double)tempPlayer->getLevel() + ((double)tempPlayer->getLevel() / 10))) << endl;
			tempEnemy->decHealth(playerDmg);
			//cout << "2-Enemy Health: " << tempEnemy->getHealth() << endl;
			//system("pause");
		}
	}
	if (retreat == 'y')
	{
		cout << "Live to fight another day\n";
		return 0;
	}
	if (tempPlayer->getHealth() <= 0)
	{
		cout << "You're dead!\n";
		//system("pause");
		return 0;
	}
	if (tempEnemy->getHealth() <= 0)
	{
		cout << "The enemy is dead! Go get an ale!\n";
		tempPlayer->incHealth(100);
		tempPlayer->incPlayerExp(tempEnemy->getexpValue());
		//system("pause");
		return 1;
	}
};

//Concepts for functions using passed in objects

void MainGame::addsector(GameMap* tempMap, int x, int y)
{
	sectorCount++;
	tempMap->addSector(x, y);
}

void MainGame::addTreasure(TreasureChest* tempChest, GameMap* tempMap, int col, int row)
{
	treasureCount++; //increase the number of treasure chests present in game
	string newItem = tempChest->randItem(randItemNum()); //determines the type, and later on amount, of treasure that will be present
	tempChest->addItem(newItem, col, row, treasureCount); //create the chest
	tempMap->setSectorTreasure(col, row, "present"); //mark the sector as having treasure
}

void MainGame::addEnemy(Enemy* tempEn, GameMap* tempMap, int col, int row)
{
	enemyCount++;
	string newEnemy = tempEn->randEnemy(randEnemyNum());
	tempEn->addEnemy(newEnemy, col, row);
	tempMap->setSectorEnemy(col, row, "present"); //mark the sector as having enemy
};