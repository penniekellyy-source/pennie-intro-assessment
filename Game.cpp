#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Game.h"

using namespace std;

Room::Room()
{
	name = " ";
	description = " ";
}

Room::Room(string roomName, string desc)
{
	name = roomName;
	desc = description;
}

void Room::enterRoom() const
{
	cout << name << endl;
	cout << description << endl << endl;
}

void roomSetup(Room rooms[], int size)
{
	if (size < 3) return; // stopping the function early
}