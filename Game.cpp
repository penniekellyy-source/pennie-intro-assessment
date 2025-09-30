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

Room::Room(string name, string desc, int setNorth, int setSouth, int setEast, int setWest)
{
	roomName = name;
	roomDescription = desc;

	north = setNorth;
	south = setSouth;
	east = setEast;
	west = setWest;
}

void Room::enterRoom() const // prints room info
{
	cout << roomName << endl;
	cout << roomDescription << endl << endl;
}

Locations::Locations()
{
	Locations(4);
}

Locations::Locations(int size)
{
	if (size > 4) return; // stopping the function early if size exceeds amount of rooms

	rooms[0] = Room("North Room", "This is the north room"); // object array, using custom constructor in room class, name & desc
	rooms[1] = Room("South Room", "This is the south room"); // placeholder names & descs
	rooms[2] = Room("East Room", "This is the east room");
	rooms[3] = Room("West Room", "This is the west room");
}

void Player::playGame()
{
	string command;
	getline(cin, command);
	stringUtil util;
	int currentRoom = 0;

	cout << "Adventure Game Test" << endl;
	cout << "Available Directions :" << endl;
	cout << "North, South, East, West" << endl << endl;

	cout << "Where will you go?" << endl;
	cin >> command;

	if (util.toUpper(command) == "GO NORTH")
	{
		currentRoom = 0;
		cout << locations.rooms[0].roomDescription << endl; // grabbing array of rooms from locations class stored in Player & its description
		playGame();
	}
	else if (util.toUpper(command) == "GO SOUTH")
	{
		currentRoom = 1;
		cout << locations.rooms[1].roomDescription << endl;
		playGame();
	}
	else if (util.toUpper(command) == "GO EAST")
	{
		currentRoom = 2;
		cout << locations.rooms[2].roomDescription << endl;
		playGame();
	}
	else if (util.toUpper(command) == "GO WEST")
	{
		currentRoom = 3;
		cout << locations.rooms[3].roomDescription << endl;
		playGame();
	}
	else
	{
		cout << "You can't go there!" << endl;
	}
}

Player::Player()
{

}

Locations::Locations()
{

}
