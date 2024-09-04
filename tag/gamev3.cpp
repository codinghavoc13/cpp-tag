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

void main()
{
	int menuOption = -1;
	while (menuOption != 0)
	{
		system("CLS");
		cout << "Welcome Menu\nSelect an option from below\n";
		cout << "1 - New Game\n";
		cout << "2 - Load Game (WIP)\n";
		cout << "0 - Exit game\n";
		cin >> menuOption;
		if (menuOption == 1)
		{
			MainGame* game = new MainGame();
			GameMap* gamemap = new GameMap();
			TreasureChest* treasureChest = new TreasureChest();
			Inventory* inventory = new Inventory();
			Player* player = new Player();
			Enemy* enemy = new Enemy();
			player->setDmgMult(2.0);
			/*The two lines below are needed to prevent the program from
			crashing after cleaning out the last treasure chest and/or
			killing the last enemy*/
			treasureChest->addItem("ispep", -1, -1, -1);
			enemy->addEnemy("ispep", -1, -1);
			game->mainGame(game, treasureChest, inventory, gamemap, player, enemy);
		}
	}
}

