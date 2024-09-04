#include "stdafx.h"
#include "sector.h"
#include "map.h"
#include "player.h"
#include <iostream>

Sector* GameMap::navigation(string direction, int mX, int mY)
{
	int option;
	if (direction == "north" || direction == "go north" || direction == "move north" || direction == "n") //north
	{
		option = 1;
	}
	else if (direction == "northeast" || direction == "go northeast" || direction == "move northeast" || direction == "ne") //northeast
	{
		option = 2;
	}
	else if (direction == "east" || direction == "go east" || direction == "move east" || direction == "e") //east
	{
		option = 3;
	}
	else if (direction == "southeast" || direction == "go southeast" || direction == "move southeast" || direction == "se") //southeast
	{
		option = 4;
	}
	else if (direction == "south" || direction == "go south" || direction == "move south" || direction == "s") //south
	{
		option = 5;
	}
	else if (direction == "southwest" || direction == "go southwest" || direction == "move southwest" || direction == "sw") //southwest
	{
		option = 6;
	}
	else if (direction == "west" || direction == "go west" || direction == "move west" || direction == "w") //west
	{
		option = 7;
	}
	else if (direction == "northwest" || direction == "go northwest" || direction == "move northwest" || direction == "nw") //northwest
	{
		option = 8;
	}
	else
	{
		cout << "Enter a valid direction\n";
		option = 0;
	}

	Sector* temp = currLoc;
	int currX = temp->x;
	int currY = temp->y;
	//int destY = currY - 1;
	//int tempY = getYValue();
	switch (option)
	{
	case 1: //north
		if (currY + 1 < mY)
		{
			temp = GameMap::searchSector(currX, (currY + 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 2: //northeast
		if (((currX + 1) < mX) && ((currY + 1) < mY))
		{
			temp = GameMap::searchSector((currX + 1), (currY + 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 3: // east
		if ((currX + 1) < mX)
		{
			temp = GameMap::searchSector((currX + 1), currY);
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 4: //southeast
		if (((currX + 1) < mX) && ((currY - 1) < mY))
		{
			temp = GameMap::searchSector((currX + 1), (currY - 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 5: //south
		if ((currY - 1) >= 0)
		{
			temp = GameMap::searchSector(currX, (currY - 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 6: //southwest
		if (((currX - 1) < mX) && ((currY - 1) < mY))
		{
			temp = GameMap::searchSector((currX - 1), (currY - 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 7: //west
		if ((currX - 1) >= 0)
		{
			temp = GameMap::searchSector((currX - 1), currY);
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	case 8: //northwest
		if (((currX - 1) < mX) && ((currY + 1) < mY))
		{
			temp = GameMap::searchSector((currX - 1), (currY + 1));
		}
		else
		{
			cout << "Can't go that way!\n";
		}
		break;
	}
	/*Need to rework this to */
	/**/
	//setPlayerX(currX);
	//setPlayerY(currY);
	//prevLoc = currLoc;
	//currLoc = temp;
	//return currLoc;
	return temp;
}