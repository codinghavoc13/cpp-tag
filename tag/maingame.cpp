// Gamev2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "map.h"
#include "sector.h"
#include "treasurechest.h"
#include "inventory.h"
#include "items.h"
#include "player.h"
#include "enemy.h"
#include "game.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib> //IMPORTANT!!!
#include <ctime> //IMPORTANT!!!
using namespace std;

int randNum();
int randItemNum();
int randEnemyNum();
int randCombatNum();

void MainGame::mainGame(MainGame* game, TreasureChest* treasureChest, Inventory* inventory, GameMap* gamemap, Player* player, Enemy* enemy)
{
	//player->setPlayerName();
	//cout << "Welcome to my game " << player->getPlayerName() << "\n";

	int test = 0;
	int sectorCount = 0;
	int treasureCount = 0;
	int enemyCount = 0;
	//char block = 219;
	string newItem;
	string newEnemy;

	srand((unsigned)time(0));
	setMapSize();
	int x = getMapX(), y = getMapY();
	int col = 0, row = 0;
	while (col != x)
	{
		while (row != y && col != x)
		{
			//Check treasure / enemy
			int checkTE = randNum() % 4;
			switch (checkTE)
			{
			case 0:
				game->addsector(gamemap, col, row);
				break;
			case 1:
				game->addsector(gamemap, col, row);
				game->addTreasure(treasureChest, gamemap, col, row);
				break;
			case 2:
				game->addsector(gamemap, col, row);
				game->addEnemy(enemy, gamemap, col, row);
				break;
			case 3:
				game->addsector(gamemap, col, row);
				game->addTreasure(treasureChest, gamemap, col, row);
				game->addEnemy(enemy, gamemap, col, row);
				break;
			}
			row++;
			/*WIP loading bar
			double complete = (double)sectorCount / (double)(game.getMapX()*game.getMapY()) * 10;
			for (int ctr = 0; ctr < complete; ctr++)
			{
			cout << block << block << complete << "%";
			}
			cout << endl;
			system("cls");*/
		}
		row = 0;
		col++;
	}

	inventory->addItem("healing potion", 16);

	cout << "Sector count: " << game->sectorCount << endl;//For test purposes only
	cout << "Treasure count: " << game->treasureCount << endl;//For test purposes only
	//cout << "Treasure list\n";
	cout << "\n-------------------------\n\n";//For test purposes only
	//treasureChest.display();//For test purposes only
	//system("pause");//For test purposes only
	cout << "Enemy count: " << game->enemyCount << endl;//For test purposes only
	//gamemap.listSectorT(game.getMapX(), game.getMapY());//For test purposes only
	cout << "\n-------------------------\n\n";//For test purposes only
	//enemy.display();//For test purposes only
	//system("pause");//For test purposes only
	//gamemap.listSectorE(game.getMapX(), game.getMapY());//For test purposes only

	/*Move into the main portion of the program*/
	char exit = 'n';
	char firstMove = 'n';

	while (exit != 'y')
	{
		string direction;
		bool winFight = true;
		Sector* newLoc = new Sector();
		Sector* temp = gamemap->currLoc;
		gamemap->displayCurrLoc();
		gamemap->displayPrevLoc();
		cout << "Current health is: " << player->getHealth() << endl;
		cout << "Enter a direction: ";
		cin.ignore();
		getline(cin, direction);
		while (direction != "quit")
		{
			//if (getXValue <= 8 && getYValue <= 8)
			//print full map
			//else
			//print scrolling map
			system("cls");
			if (direction == "menu")
			{
				int option = 0;
				while (option != 5)
				{
					cout << "Select an option from the list below:\n";
					cout << "1)   View Scrolling Map\n";
					cout << "2)   View Entire Map (only for maps 8x8 or smaller)\n";
					cout << "3)   View Area Around Player\n";
					cout << "4)   View List of Control Words\n";
					cout << "5)   Return to Game\n";
				}
			}
			else
			{
				newLoc = gamemap->navigation(direction, game->getMapX(), game->getMapY());
				winFight = true;
				bool cont = true;

				if (newLoc->enemy == "present")
				{
					cont = false;
					string fof;
					cout << "Enemy found in (" << newLoc->x << "," << newLoc->y << ")!\n";
					bool cont1 = false;
					while (cont1 == false)
					{
						cout << "Your health is: " << player->getHealth() << endl;
						cout << "Do you want to fight or retreat? (choose fight or retreat) ";
						cin >> fof;
						if ((fof == "fight") || (fof == "retreat"))
							cont1 = true;
						else if ((fof != "fight") || (fof != "retreat"))
							cout << "Please select fight or retreat\n";
					}
					if (fof == "fight")
					{
						winFight = game->combatResult(newLoc, player, enemy, gamemap, inventory);
						cout << "Sector clear of enemy\n";
						if (newLoc->status != "start")
						{
							gamemap->setCurrEnemyStat("clear");
						}
					}
					else
					{
						winFight = false;
						temp = gamemap->prevLoc;
					}
				}
				else if (cont == true)
				{
					if (newLoc->treasure == "present")
					{
						game->foundTreasure(newLoc, treasureChest, inventory, gamemap);
					}
				}
			}
			gamemap->displayPrevLoc();
			if (winFight == true)
			{
				gamemap->currLoc = newLoc;
			}
			if (winFight == false)
			{
				gamemap->currLoc = temp;
			}
			gamemap->prevLoc = gamemap->currLoc;
			gamemap->displayCurrLoc();
			cout << "Current health is: " << player->getHealth() << endl;
			cout << "Enter a new direction: ";
			cin >> direction;
		}
		exit = 'y';
	}
}