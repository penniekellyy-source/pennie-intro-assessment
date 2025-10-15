#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Room::Room()
{
	roomName = " ";
	roomDescription = " ";

	north = south = east = west = -1; // -1 = there is no room in this direction

	isLocked = false;
	inspected = false;
	visited = false;

	hasEnemy = false;
	roomEnemy = Enemy("None", 0, 0);
	roomEnemy.defeat();
}

Room::Room(string name, string desc)
{
	roomName = name;
	roomDescription = desc;

	north = south = east = west = -1;

	isLocked = false;
	inspected = false;
	visited = false;
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
	visited = false;
}

Locations::Locations(int size)
{
	//if (size > 5) return; // stopping the function early if size exceeds amount of rooms

	// object array, using custom constructor in room class, name & desc
	
	rooms[0] = Room(
		"Starting Room",
		"You awaken in a quiet, unfamiliar room. The air is cool and faintly damp, and somewhere nearby, water drips at a steady rhythm.\n"
		"The old wooden floor creaks gently beneath your weight as you rise. Four doors stand on each wall, their faded paint suggesting years of neglect.\n"
		"A strange stillness lingers here—not threatening, but unsettling. Perhaps exploring will lead to answers.\n\n",
		1, 2, 3, 4);

	rooms[1] = Room(
		"North Room",
		"You step into the north room. The wooden floor groans softly underfoot.\n"
		"A faint scent of sage clings to the dusty air, as though someone was here long ago.\n"
		"Furniture sits beneath pale cloths, their shapes suggesting forgotten lives. The silence is almost too perfect.\n\n",
		-1, 0, -1, -1);

	rooms[2] = Room(
		"South Room",
		"The south room greets you with a muted calm. Dust drifts lazily in the pale light,\n"
		"and the walls seem to hum softly with the building's age. Something about this room feels like it's waiting for something to happen.\n\n"
		"You notice an oddly positioned bookshelf on the north wall of the room.",
		5, -1, -1, -1);

	rooms[3] = Room(
		"East Room",
		"The east room carries a faint, earthy smell of damp wood. The corners are dim, and the air feels heavier here.\n"
		"You catch a glimpse of movement—or perhaps it was just the shifting of the old house.\n",
		-1, -1, -1, 0);

	rooms[4] = Room(
		"West Room",
		"You step inside the west room, and a cool draft brushes against your skin.\n"
		"The faint hum of an unseen vent breaks the silence.\n"
		"The worn carpet and fading floral wallpaper suggest this room was once cared for, long before it was abandoned to time.\n\n",
		-1, -1, 0, -1);

	rooms[5] = Room(
		"Hidden Room",
		"You find a narrow opening that leads into a small hidden chamber.\n"
		"It's quiet and unexpectedly warm here, as if untouched by the outside chill.\n\n",
		-1, 2, -1, -1);
	
	rooms[3].isLocked = true;
	rooms[4].isLocked = true;
	
	rooms[0].roomItem = Item();
	rooms[1].roomItem = Key(); // rusty key in north room
	rooms[2].roomItem = Item();
	rooms[3].roomItem = Item();
	rooms[4].roomItem = Code(); // east door code in west room
	rooms[5].roomItem = Item("Healing Potion", "Restores some of your health."); // this doesn't work yet lol

	rooms[1].roomEnemy = Enemy("Goblin", 30, 5);
	rooms[1].hasEnemy = true;
	rooms[1].roomEnemy.isDefeated = false;

	rooms[3].roomEnemy = Enemy("Skeleton", 50, 10);
	rooms[3].hasEnemy = true;
	rooms[3].roomEnemy.isDefeated = false;

	rooms[4].roomEnemy = Enemy("Zombie", 70, 15);
	rooms[4].hasEnemy = true;
	rooms[4].roomEnemy.isDefeated = false;

	rooms[0].hasEnemy = false; // starting room
	rooms[2].hasEnemy = false; // safe room
	rooms[5].hasEnemy = false; // <<<
}

Locations::Locations() : Locations(6){} // default constructor runs this ^^^^

void Player::playGame()
{
	cout << "You awaken in a quiet, unfamiliar room. The air is cool and faintly damp, and somewhere nearby, water drips at a steady rhythm.\n";
	cout << "The old wooden floor creaks gently beneath your weight as you rise. Four doors stand on each wall, their faded paint suggesting years of neglect.\n";
	cout << "A strange stillness lingers here—not threatening, but unsettling. Perhaps exploring will lead to answers.\n\n";
	cout << "Maybe you should look around...?\n\n";
	cout << "Type 'help' for a list of commands." << endl << endl;

	string command;
	stringUtil util;
	currentRoom = 0;

	if (locations.rooms[currentRoom].visited)
	{
		cout << "You haven't found anything of use yet! Try looking around first." << endl << endl;
	}

	while (true)
	{
		cout << "> ";
		getline(cin, command);
		cout << endl;

		string cmd = util.toUpper(command);

		// ==== HELP ====
		if (util.find(cmd, "HELP"))
		{
			showHelp();
		}

		// ==== INSPECT ====
		else if (util.find(cmd, "INSPECT"))
		{
			cout << "You take a look around the room..." << endl;
			if (locations.rooms[currentRoom].roomItem.getItemName() == "Nothing")
				cout << "You didn't find anything of use." << endl << endl;
			else
				cout << "You found " << locations.rooms[currentRoom].roomItem.getItemName()
				<< "! " << locations.rooms[currentRoom].roomItem.getItemDescription() << endl << endl;

			locations.rooms[currentRoom].inspected = true;
		}

		// ==== TAKE ====
		else if (util.find(cmd, "TAKE"))
		{
			pickUpItem();
		}

		// ==== INVENTORY ====
		else if (util.find(cmd, "INVENTORY"))
		{
			showInventory();
		}

		// ==== USE ====
		else if (util.find(cmd, "USE"))
		{
			useItem();
		}

		// ==== QUIT ====
		else if (util.find(cmd, "QUIT"))
		{
			cout << "Thanks for playing!" << endl;
			return;
		}

		// ==== MOVE NORTH ====
		else if (util.find(cmd, "NORTH"))
		{
			moveTo(locations.rooms[currentRoom].north);
		}

		// ==== MOVE SOUTH ====
		else if (util.find(cmd, "SOUTH"))
		{
			moveTo(locations.rooms[currentRoom].south);
		}

		// ==== MOVE EAST ====
		else if (util.find(cmd, "EAST"))
		{
			moveTo(locations.rooms[currentRoom].east);
		}

		// ==== MOVE WEST ====
		else if (util.find(cmd, "WEST"))
		{
			moveTo(locations.rooms[currentRoom].west);
		}

		// ==== BACK ====
		else if (util.find(cmd, "BACK"))
		{
			currentRoom = 0;
			cout << "You return to the " << locations.rooms[currentRoom].roomName << ".\n\n";
		}

		// ==== UNKNOWN ====
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
	cout << "- 'North' - Move north of the current room\n";
	cout << "- 'South' - Move south of the current room\n";
	cout << "- 'East' - Move east of the current room\n";
	cout << "- 'West' - Move west of the current room\n";
	cout << "- 'Quit' - Quit game\n";
	cout << "- 'Inspect' - Look around the current room\n";
	cout << "- 'Take' - Pick up item\n";
	cout << "- 'Inventory' - Inventory list\n";
	cout << "- 'Use' - Use an item\n\n";
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

	if (currentItem.getItemName() == "Nothing") // checks if the room has an item, default name means room is empty
	{
		cout << "There is nothing of use here." << endl << endl;
		return;
	}

	inventory[itemCount] = currentItem; // add current item into player's inventory array
	itemCount++; // increases number of items player has

	cout << "You picked up " << currentItem.getItemName() << "!" << endl << endl;

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
		cout << "- " << inventory[i].getItemName() << " : " << inventory[i].getItemDescription() << endl;
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
		cout << i + 1 << ". " << inventory[i].getItemName() << endl << endl;
	}

	string input;
	getline(cin, input);
	int choice;

	try
	{
		choice = stoi(input);
	}
	catch (invalid_argument&)
	{
		cout << "Invalid input! Please enter a number." << endl << endl;
		return;
	}

	if (choice < 1 || choice > itemCount)
	{
		cout << "Invalid choice." << endl << endl;
		return;
	}

	Item selectedItem = inventory[choice - 1];
	cout << endl;

	// manually check type instead of polymorphism
	if (selectedItem.getItemName() == "Rusty Key")
	{
		if (currentRoom == 0)
		{
			cout << "You use the Rusty Key on the west door." << endl;
			cout << "The lock clicks open!" << endl << endl;
			locations.rooms[4].isLocked = false;

			for (int i = choice - 1; i < itemCount - 1; i++)
				inventory[i] = inventory[i + 1];
			itemCount--;
		}
		else
		{
			cout << "You can't use that here! Try using it in front of the west door in the starting room.\n\n";
		}
	}
	else if (selectedItem.getItemName() == "East Door Code")
	{
		if (currentRoom == 0)
		{
			cout << "You insert the East Door Code...\nThe east door lock beeps and clicks open!\n\n";
			locations.rooms[3].isLocked = false;

			for (int i = choice - 1; i < itemCount - 1; i++)
				inventory[i] = inventory[i + 1];
			itemCount--;
		}
		else
		{
			cout << "You can't use that here! Try using it in front of the east door in the starting room.\n\n";
		}
	}
	else
	{
		selectedItem.Use();
	}
}

void Player::moveTo(int nextRoom)
{
		if (nextRoom == -1)
	{
		cout << "You can't go that way!" << endl << endl;
		return;
	}
	else if (locations.rooms[nextRoom].isLocked)
	{
		cout << "The door is locked. Maybe you need a key?" << endl << endl;
		return;
	}
	
	currentRoom = nextRoom;

	// checks for enemies first & makes sure it is impossible to accidentally battle an "unknown enemy"
	Enemy& enemy = locations.rooms[currentRoom].roomEnemy;
	if(locations.rooms[currentRoom].hasEnemy && !enemy.isDefeated && enemy.getEntityName() != "None")
	{
		int encounterChance = rand() % 100;
		if (encounterChance < 85)
		{
			battle(locations.rooms[currentRoom].roomEnemy);
		}
		else
		{
			cout << "You hear movement nearby, but nothing happens...\n\n";
		}
	}

	if(!isDead())
	{
		if (!locations.rooms[currentRoom].visited)
		{
			cout << locations.rooms[currentRoom].roomDescription << endl;
			locations.rooms[currentRoom].visited = true;
		}
		else
			cout << "You return to the " << locations.rooms[currentRoom].roomName << ".\n\n";
	}
}

void Player::battle(Enemy& enemy)
{
	cout << "You encounter " << enemy.getEntityName() << "!\n\n";

	stringUtil util;
	while (!enemy.isDead() && !isDead())
	{
		cout << "Your Health : " << entityHealth << " | " << enemy.getEntityName() << " Health : " << enemy.getEntityHealth() << endl << endl;
		cout << "Choose an action: \n1. Attack\n2. Use Item\n3. Flee\n\n";

		string input;
		cout << "> ";
		getline(cin, input);
		cout << endl;
		int choice;

		try
		{
			choice = stoi(input);
		}
		catch (invalid_argument&)
		{
			cout << "Invalid input! Please enter a number." << endl << endl;
			continue; // repeat the battle turn
		}

		if (choice == 1)
		{
			cout << "You attack " << enemy.getEntityName() << " for " << entityAttack << " damage!\n";
			enemy.takeDamage(entityAttack);
		}
		else if (choice == 2)
		{
			useItem();
		}
		else if (choice == 3)
		{
			cout << "You manage to flee past the " << enemy.getEntityName() << "!\n\n";
			return;
		}
		else
		{
			cout << "Invalid action!\n\n";
			continue;
		}

		if (!enemy.isDead()) // gives enemies variation in damage
		{
			int minDmg = enemy.getEntityAttack() - 3;
			int maxDmg = enemy.getEntityAttack() + 3;
			if (minDmg < 1) minDmg = 1;

			int dmg = minDmg + (rand() % (maxDmg - minDmg + 1));
			cout << enemy.getEntityName() << " attacks you for " << dmg << " damage!\n\n";
			takeDamage(dmg);
		}
	}

	if (isDead())
		cout << "You have been defeated! Game over.\n";
	else
	{
		cout << "You defeated " << enemy.getEntityName() << "!\n\n";
		enemy.defeat();
	}
}