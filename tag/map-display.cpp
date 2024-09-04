#include "stdafx.h"
#include "sector.h"
#include "map.h"
#include "player.h"
#include <iostream>

void GameMap::scrollingMap(int, int) //This is used when the map is bigger than 8x8
{
	int x = getXValue();
	int y = getYValue();
	int scrollH = 0, scrollV = 0, scrollMax = 8;
	char scroll = 'a';
	/*First loop: set col equal to scrollMax (8) minus 1 (displaying 8x8 means 0-7 when it starts) plus scrollV to control moving around the map*/
	while (scroll != 'q')
	{
		system("CLS");
		cout << "scrollH: " << scrollH << " | scrollV: " << scrollV << endl;
		for (int col = ((scrollMax - 1) + scrollV); col >= scrollV; col--)
		{
			for (int row = scrollH; row < (scrollMax + scrollH); row++)
			{
				cout << "+---+";
			}
			cout << endl;
			for (int row1 = scrollH; row1 < (scrollMax + scrollH); row1++)
			{
				cout << "|" << GameMap::getSectorStatus(row1, col) << "|";
			}
			cout << endl;
			for (int row2 = scrollH; row2 < (scrollMax + scrollH); row2++)
			{
				cout << "+---+";
			}
			cout << endl;
		}
		cout << "Scroll option: \n";
		cin >> scroll;
		switch (scroll)
		{
		case 'u':
			if (scrollV == y - scrollMax)
				break;
			else
			{
				scrollV += 1;
				break;
			}
		case 'd':
			if (scrollV == 0)
				break;
			else
			{
				scrollV -= 1;
				break;
			}
		case 'l':
			if (scrollH == 0)
				break;
			else
			{
				scrollH -= 1;
				break;
			}
		case 'r':
			if (scrollH == x - scrollMax)
				break;
			else
			{
				scrollH += 1;
				break;
			}
		}
	}
}

void GameMap::listSector(int, int)
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
			cout << "|" << row1 << "," << col << "|";
			//cout << "|" << GameMap::getSectorStatus(row1, col) << "|";
		}
		cout << endl;
		for (int row2 = 0; row2 < y; row2++)
		{
			cout << "+---+";
		}
		cout << endl;
	}
}

void GameMap::listSectorT(int x, int y)
{
	for (int col = (x - 1); col >= 0; col--)
	{
		for (int row = 0; row < y; row++)
		{
			cout << "+---+";
		}
		cout << endl;
		for (int row1 = 0; row1 < y; ++row1)
		{
			//cout << "|" << row1 << "," << col << "|";
			cout << "|" << GameMap::getSectorTreasure(row1, col) << "|";
		}
		cout << endl;
		for (int row2 = 0; row2 < y; row2++)
		{
			cout << "+---+";
		}
		cout << endl;
	}
}

void GameMap::listSectorE(int x, int y)
{
	for (int col = (x - 1); col >= 0; col--)
	{
		for (int row = 0; row < y; row++)
		{
			cout << "+---+";
		}
		cout << endl;
		for (int row1 = 0; row1 < y; ++row1)
		{
			//cout << "|" << row1 << "," << col << "|";
			cout << "|" << GameMap::getSectorEnemy(row1, col) << "|";
		}
		cout << endl;
		for (int row2 = 0; row2 < y; row2++)
		{
			cout << "+---+";
		}
		cout << endl;
	}
}

void GameMap::centerMap(int, int)
{
	int x = getPlayerX();
	int y = getPlayerY();
	for (int col = (x + 7); col >= 0; col--)
	{
		for (int row = 0; row < y; row++)
		{
			cout << "+---+";
		}
		cout << endl;
		for (int row1 = 0; row1 < y; ++row1)
		{
			cout << "|" << row1 << "," << col << "|";
			//cout << "|" << GameMap::getSectorStatus(row1, col) << "|";
		}
		cout << endl;
		for (int row2 = 0; row2 < y; row2++)
		{
			cout << "+---+";
		}
		cout << endl;
	}
	system("pause");
};