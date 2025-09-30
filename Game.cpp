#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Game.h"

using namespace std;

Room::Room()
{
	roomName = " ";
	roomDescription = " ";
}

Room::Room(string name, string desc)
{
	roomName = name;
	roomDescription = desc;
}

void Room::enterRoom() const // prints room info
{
	cout << roomName << endl;
	cout << roomDescription << endl << endl;
}

void roomSetup(Room rooms[], int size)
{
	if (size < 4) return; // stopping the function early if size exceeds amount of rooms

	rooms[0] = Room("North Room", "This is the north room"); // object array, using custom constructor in room class, name & desc
	rooms[1] = Room("South Room", "This is the south room"); // placeholder names & descs
	rooms[2] = Room("East Room", "This is the east room");
	rooms[3] = Room("West Room", "This is the west room");
}

void playGame(Room rooms[], int size)
{
	int currentRoom = 0;
	string command;

	cout << "Adventure Game Test" << endl;
	cout << "Available Directions :" << endl;
	cout << "North, South, East, West" << endl << endl;

	cout << "Where will you go?" << endl;
	cin >> command;

	if (command == "north")
	{
		currentRoom = 0;
	}
	else if (command == "south")
	{
		currentRoom = 1;
	}
	else if (command == "east")
	{
		currentRoom = 2;
	}
	else if (command == "west")
	{
		currentRoom = 3;
	}
	else
	{
		cout << "You can't go there!" << endl;
	}
}


