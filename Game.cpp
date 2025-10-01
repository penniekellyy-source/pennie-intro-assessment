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
	cout << "Welcome to Text Adventure Game!" << endl << endl; // placeholder
	cout << "Type 'help' for a list of commands." << endl << endl;

	string command;
	stringUtil util;
	int currentRoom = 0;

	while (true)
	{
		cout << "Where will you go?" << endl << endl;

		cout << "> ";
		getline(cin, command); cout << endl; // gets the whole line instead of just one word

		string cmd = util.toUpper(command);

		if (cmd == "HELP")
		{
			showHelp();
		}
		else if (cmd == "QUIT")
		{
			cout << "Thanks for playing!" << endl;
			return;
		}

		else if (util.toUpper(command) == "GO NORTH")
		{
			currentRoom = 0;
			cout << locations.rooms[0].roomDescription << endl;
			// grabbing array of rooms from locations class stored in player class & couts its description
		}
		else if (util.toUpper(command) == "GO SOUTH")
		{
			currentRoom = 1;
			cout << locations.rooms[1].roomDescription << endl;
		}
		else if (util.toUpper(command) == "GO EAST")
		{
			currentRoom = 2;
			cout << locations.rooms[2].roomDescription << endl;
		}
		else if (util.toUpper(command) == "GO WEST")
		{
			currentRoom = 3;
			cout << locations.rooms[3].roomDescription << endl;
		}
		else
		{
			cout << "You can't go there!" << endl << endl;
		}
	}
}
void Player::showHelp()
{
	cout << "\n === Command list ===\n\n";
	cout << "1. 'Help' - Command list\n";
	cout << "2. 'Go North' - Move to north room\n";
	cout << "3. 'Go South' - Move to south room\n";
	cout << "4. 'Go East' - Move to east room\n";
	cout << "5. 'Go West' - Move to west room\n";
	cout << "6. 'Quit' - Quit game\n\n";
} 
	
Player::Player()
{

}
