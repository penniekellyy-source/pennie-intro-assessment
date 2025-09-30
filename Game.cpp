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

	north = -1; // initialize variables in constructor
	south = -1;
	east = -1;
	west = -1;
}

Room::Room(string roomName, string desc)
{
	name = roomName;
	desc = description;

	north = -1; // since arrays start at 0, -1 means "this room doesn't exist"
	south = -1;
	east = -1;
	west = -1;
}

void Room::enterRoom() const
{
	cout << name << endl;
	cout << description << endl << endl;


}

void roomSetup(Room rooms[], int size)
{
	if (size < 4) return; // stopping the function early if size exceeds amount of rooms

	rooms[0] = Room(" ", " "); // object array, using custom constructor in room class, name & desc
	rooms[1] = Room(" ", " ");
	rooms[2] = Room(" ", " ");
	rooms[3] = Room(" ", " ");
}

