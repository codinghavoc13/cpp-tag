#pragma once
#include <string>
using namespace std;

class Sector
{
public:
	Sector() {};
	~Sector() {};
	int x;
	int y;
	string treasure = "none";
	string enemy = "none";
	string status = "new";
	Sector* next = nullptr;
};