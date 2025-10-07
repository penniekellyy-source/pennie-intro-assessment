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

	north = -1; // -1 = there is no room in this direction
	south = -1;
	east = -1;
	west = -1;

	isLocked = false;
}

Room::Room(string name, string desc)
{
	roomName = name;
	roomDescription = desc;

	north = -1;
	south = -1;
	east = -1;
	west = -1;

	isLocked = false;
}

Room::Room(string name, string desc, int setNorth, int setSouth, int setEast, int setWest)
{
	roomName = name;
	roomDescription = desc;

	north = setNorth;
	south = setSouth;
	east = setEast;
	west = setWest;
	
	isLocked = false;
}

Locations::Locations(int size)
{
	if (size > 4) return; // stopping the function early if size exceeds amount of rooms

	// object array, using custom constructor in room class, name & desc
	rooms[0] = Room("North Room", "You cautiously walk forward.\nYou find yourself in a dimly lit living room.\n"); 
	rooms[1] = Room("South Room", "You walk through the door behind you, only to find a spacious, empty room.\n"); // placeholder names & descs
	rooms[2] = Room("East Room", "You take a step through the door on your right, and you were greeted by an empty office.\n");
	rooms[3] = Room("West Room", "You walk into the west room. It's revealed to be a large library that smells of freshly burnt sage.\n");
	rooms[3].isLocked = true;

	rooms[0].roomItem = Key();
	rooms[1].roomItem = Item();
	rooms[2].roomItem = Item();
	rooms[3].roomItem = Item();
}

Locations::Locations() : Locations(4){} // default constructor runs this ^^^^

Player::Player()
{

}

void Player::playGame()
{
	cout << "Welcome to Text Adventure Game!" << endl << endl; // placeholder
	cout << "Type 'help' for a list of commands." << endl << endl;
	cout << "What will you do?" << endl << endl;

	string command;
	stringUtil util;
	currentRoom = 0;

	while (true)
	{
		cout << "> ";
		getline(cin, command); cout << endl; // gets the whole line instead of just one word

		string cmd = util.toUpper(command);

		if (cmd == "HELP")
		{
			showHelp();
		}
		else if (cmd == "INSPECT")
		{
			cout << "You take a look around the room." << endl << endl;
			cout << "You found " << locations.rooms[currentRoom].roomItem.getName() << "!" << endl << endl;
			cout << locations.rooms[currentRoom].roomItem.getDescription() << endl << endl;
		}
		else if (cmd == "TAKE")
		{
			pickUpItem();
		}
		else if (cmd == "INVENTORY")
		{
			showInventory();
		}
		else if (cmd == "USE")
		{
			useItem();
		}
		else if (cmd == "QUIT")
		{
			cout << "Thanks for playing!" << endl;
			return;
		}
		else if (cmd == "GO NORTH")
		{
			currentRoom = 0;
			cout << locations.rooms[0].roomDescription << endl;
			cout << "A faint glint on a dusty side table catches your eye." << endl << endl;
		}
		else if (cmd == "GO SOUTH")
		{
			currentRoom = 1;
			cout << locations.rooms[1].roomDescription << endl;
		}
		else if (cmd == "GO EAST")
		{
			currentRoom = 2;
			cout << locations.rooms[2].roomDescription << endl;
		}
		else if (cmd == "GO WEST")
		{
			if (locations.rooms[3].isLocked)
			{
				cout << "The door is locked. Maybe you need a key?" << endl << endl;
			}
			else
			{
				currentRoom = 3;
				cout << locations.rooms[3].roomDescription << endl;
			}
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
	cout << "- 'Help' - Command list\n";
	cout << "- 'Go North' - Move to north room\n";
	cout << "- 'Go South' - Move to south room\n";
	cout << "- 'Go East' - Move to east room\n";
	cout << "- 'Go West' - Move to west room\n";
	cout << "- 'Quit' - Quit game\n";
	cout << "- 'Inspect' - Look around the current room\n";
	cout << "- 'Take' - Pick up item\n";
	cout << "- 'Inventory' - Inventory list\n";
	cout << "- 'Use' - Use an item\n";
	cout << "- 'Stats' - Display player stats\n\n";

}

void Player::pickUpItem()
{
	if (itemCount >= 5) // checks if the player's inventory is already full
	{
		cout << "Your inventory is full!" << endl << endl;;
		return; // stops function early
	}

	Item currentItem = locations.rooms[currentRoom].roomItem; // gets item in current room player is in

	if (currentItem.getName() == "Nothing") // checks if the room has an item, default name means room is empty
	{
		cout << "There is nothing of use here." << endl << endl;
	}

	inventory[itemCount] = currentItem; // add current item into player's inventory array
	itemCount++; // increases number of items player has

	cout << "You picked up " << currentItem.getName() << "!" << endl << endl;

	locations.rooms[currentRoom].roomItem = Item(); // resets to default to remove item from the room
}

void Player::showInventory()
{
	if (itemCount == 0)
	{
		cout << "Your inventory is empty!" << endl << endl;
		return;
	}

	cout << "=== Inventory ===" << endl << endl;
	for (int i = 0; i < itemCount; i++)
	{
		cout << "- " << inventory[i].getName() << ": " << inventory[i].getNewDescription() << endl;
	}
}

void Player::useItem()
{
	if (itemCount == 0)
	{
		cout << "You have nothing to use!" << endl << endl;
		return;
	}

	cout << "Which item would you like to use?" << endl;
	for (int i = 0; i < itemCount; i++)
	{
		cout << i + 1 << ". " << inventory[i].getName() << endl; // converts 0, 1, 2... to 1, 2, 3..., calls getName() and prints
	}

	string input;
	getline(cin, input);
	int choice = stoi(input); // string to integer

	if (choice < 1 || choice > itemCount)
	{
		cout << "Invalid choice." << endl;
		return;
	}

	Item selectedItem = inventory[choice - 1];
	cout << endl;

	if (selectedItem.getType() == "Key")
	{
		cout << "You use the Rusty Key." << endl;
		cout << "The lock clicks open!" << endl;
		locations.rooms[3].isLocked = false; // unlocks west room
	}
	else
	{
		selectedItem.Use();
	}
}	

