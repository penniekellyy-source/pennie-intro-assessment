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

Locations::Locations(int size)
{
	if (size > 4) return; // stopping the function early if size exceeds amount of rooms

	rooms[0] = Room("North Room", "This is the north room\n"); // object array, using custom constructor in room class, name & desc
	rooms[1] = Room("South Room", "This is the south room\n"); // placeholder names & descs
	rooms[2] = Room("East Room", "This is the east room\n");
	rooms[3] = Room("West Room", "This is the west room\n");
}

Locations::Locations() : Locations(4){}; // default constructor runs this ^^^^

void Player::playGame()
{
	string command;
	stringUtil util;
	int currentRoom = 0;

	while (true)
	{
		cout << "Where will you go?" << endl << endl;
		getline(cin, command); cout << endl; // gets the whole line instead of just one word

		if (util.toUpper(command) == "GO NORTH")
	{
		currentRoom = 0;
		cout << locations.rooms[0].roomDescription << endl;
		// grabbing array of rooms from locations class stored in player class & couts its description
		playGame(); // reruns playGame function from the beginning
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
	}
	

Player::Player()
{

}
