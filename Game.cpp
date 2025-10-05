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
}

Room::Room(string name, string desc)
{
	roomName = name;
	roomDescription = desc;

	north = -1;
	south = -1;
	east = -1;
	west = -1;
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

	// object array, using custom constructor in room class, name & desc
	rooms[0] = Room("North Room", "You cautiously walk forward.\nYou find yourself in a dimly lit living room.\nA faint glint on a dusty side table catches your eye.\n"); 
	rooms[1] = Room("South Room", "This is the south room\n"); // placeholder names & descs
	rooms[2] = Room("East Room", "This is the east room\n");
	rooms[3] = Room("West Room", "This is the west room\n");

	rooms[0].roomItem = Item("Rusty Key", "A rusty key rests beneath a pile of unopened mail on the side table.", "A rusty key\n");
	rooms[1].roomItem = Item("Item 2", "This is item 2", "Item 2 description\n");
	rooms[2].roomItem = Item("Item 3", "This is item 3", "Item 3 description\n");
	rooms[3].roomItem = Item("Item 4", "This is item 4", "Item 4 description\n");
}

Locations::Locations() : Locations(4){} // default constructor runs this ^^^^

//Entity::Entity()
//{
//	currentRoom = 0;
//}
//

void Player::playGame()
{
	cout << "Welcome to Text Adventure Game!" << endl << endl; // placeholder
	cout << "Type 'help' for a list of commands." << endl << endl;

	cout << "Y
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
		else if (cmd == "QUIT")
		{
			cout << "Thanks for playing!" << endl;
			return;
		}
		else if (cmd == "GO NORTH")
		{
			currentRoom = 0;
			cout << locations.rooms[0].roomDescription << endl;
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
	cout << "- 'Help' - Command list\n";
	cout << "- 'Go North' - Move to north room\n";
	cout << "- 'Go South' - Move to south room\n";
	cout << "- 'Go East' - Move to east room\n";
	cout << "- 'Go West' - Move to west room\n";
	cout << "- 'Quit' - Quit game\n";
	cout << "- 'Inspect' - Look around the current room\n";
	cout << "- 'Take' - Pick up item\n";
	cout << "- 'Inventory' - Inventory list\n\n";

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

Player::Player()
{
	itemCount = 0;
}
