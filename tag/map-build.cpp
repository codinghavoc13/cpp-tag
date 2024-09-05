#include "stdafx.h"
#include "sector.h"
#include "map.h"
#include "player.h"
#include "treasurechest.h"
#include <iostream>

//int randNum();
//int randItem();

void GameMap::addSector(int x, int y)
{
	Sector* newSector = new Sector;
	newSector->x = x;
	newSector->y = y;
	Sector* temp = start;
	if (start == nullptr)
	{
		start = newSector;
		currLoc = newSector;
		prevLoc = newSector;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			temp->next = newSector;
			newSector->next = nullptr;
		}
	}
	setSectorStatus(0, 0, "start");
};

