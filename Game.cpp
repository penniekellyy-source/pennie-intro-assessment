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
	inspected = false;
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
	inspected = false;
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
	inspected = false;
}

Locations::Locations(int size)
{
	if (size > 4) return; // stopping the function early if size exceeds amount of rooms

	// object array, using custom constructor in room class, name & desc
	
	rooms[0] = Room("Starting Room", " ");
	rooms[1] = Room("North Room", "You cautiously step into the north room, the floor creaking beneath you.\n\nYou were immediately greeted by the smell of sulfur,"
		"and you were practically inhaling dust.\nThe room was empty save for a few sets of furniture covered with thick white cloths.\n");
	rooms[2] = Room("South Room", "");
	rooms[3] = Room("East Room", "");
	rooms[4] = Room("West Room", "");
	
	rooms[3].isLocked = true;
	rooms[4].isLocked = true;
	
	rooms[0].roomItem = Item();
	rooms[1].roomItem = Key();
	rooms[2].roomItem = Item();
	rooms[3].roomItem = Item();
	rooms[4].roomItem = Code();
}

Locations::Locations() : Locations(4){} // default constructor runs this ^^^^

Player::Player()
{
	itemCount = 0;
}

void Player::playGame()
{
	cout << "You wake up in an unfamiliar room.\nIt smells of mildew, and the sound of water dripping from the ceiling can be heard.\n\nThe distressed wooden planks beneath you are damp and noisy as you stand"
	" up and dust yourself off,\ntaking note of your surroundings.\n\nYou seemed to be in a very small room with one door on each wall that surrounded you.\nYou wonder if the"
	" rooms' contents can give you answers as to how you wound up here...\nand maybe how to get out.\n\n";
	cout << "Maybe you should look around...\n\n";
	cout << "Type 'help' for a list of commands." << endl << endl;

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
			cout << "You take a look around the room..." << endl;
			cout << "You found " << locations.rooms[currentRoom].roomItem.getName() << "! " << locations.rooms[currentRoom].roomItem.getDescription() << endl << endl;

			locations.rooms[currentRoom].inspected = true; // checks if the room has been inspected to prevent the player being able to prematurely grab an item before inspecting the room
		}
		else if (cmd == "TAKE")
		{
			pickUpItem();
		}
		else if (util.find(cmd, "INVENTORY"))
		{
			showInventory();
		}
		else if (util.find(cmd,"USE"))
		{
			useItem();
		}
		else if (util.find(cmd, "QUIT"))
		{
			cout << "Thanks for playing!" << endl;
			return;
		}
		else if (util.find(cmd, "NORTH"))
		{
			currentRoom = 1;
			cout << locations.rooms[1].roomDescription << endl;
			cout << "A faint glint on an uncovered, dusty side table catches your eye." << endl << endl;
		}
		else if (util.find(cmd, "SOUTH"))
		{
			currentRoom = 2;
			cout << locations.rooms[2].roomDescription << endl;
		}
		else if (util.find(cmd, "EAST"))
		{
			if (locations.rooms[3].isLocked)
			{
				cout << "Looks like you'll need a 4-digit code to open this door." << endl << endl;
			}
			else
			{
				currentRoom = 3;
				cout << locations.rooms[3].roomDescription << endl;
			}
		}
		else if (util.find(cmd, "WEST"))
		{
			if (locations.rooms[4].isLocked)
			{
				cout << "The door is locked. Maybe you need a key?" << endl << endl;
			}
			else
			{
				currentRoom = 4;
				cout << locations.rooms[4].roomDescription << endl;
			}
		}
		else if (util.find(cmd, "BACK"))
		{
			currentRoom = 0;
			cout << "You return to the room you woke up in.\n\n";
		}
		else
		{
			cout << "Unknown command. Type 'help' for a list of commands." << endl << endl;
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

	if (!locations.rooms[currentRoom].inspected) // checks if the player has inspected the room or not to avoid making premature commands
	{
		cout << "You haven't found anything of use yet! Try looking around first." << endl << endl;
		return;
	}

	Item currentItem = locations.rooms[currentRoom].roomItem; // gets item in current room player is in

	if (currentItem.getName() == "Nothing") // checks if the room has an item, default name means room is empty
	{
		cout << "There is nothing of use here." << endl << endl;
		return;
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
		cout << "- " << inventory[i].getName() << " : " << inventory[i].getDescription() << endl;
	}
}

void Player::useItem()
{
	if (itemCount == 0)
	{
		cout << "You have nothing to use!" << endl << endl;
		return;
	}

	cout << "Which item would you like to use?" << endl << endl;
	for (int i = 0; i < itemCount; i++)
	{
		cout << i + 1 << ". " << inventory[i].getName() << endl << endl; // converts 0, 1, 2... to 1, 2, 3..., calls getName() and prints
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

	// manually check type instead of polymorphism
	if (selectedItem.getName() == "Rusty Key")
	{
		if (currentRoom == 4 && locations.rooms[4].isLocked)
		{
			cout << "You use the Rusty Key." << endl;
			cout << "The lock clicks open!" << endl << endl;
			locations.rooms[4].isLocked = false; // unlocks west room
		}

		for (int i = choice - 1; i < itemCount - 1; i++)
		{
			inventory[i] = inventory[i + 1];
		}
		itemCount--;
	}
	else if (selectedItem.getName() == "East Door Code")
	{
		if (currentRoom == 3 && locations.rooms[3].isLocked)
		{
			cout << "You insert the East Door Code...\nThe lock beeps and clicks open.\n\n";
			locations.rooms[3].isLocked = false;
		}

		for (int i = choice - 1; i < itemCount - 1; i++)
		{
			inventory[i] = inventory[i + 1];
		}
		itemCount--;
	}
	else
	{
		selectedItem.Use();
	}
}	
