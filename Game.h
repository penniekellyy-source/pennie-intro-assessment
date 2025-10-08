#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Entity
{
protected:


public:

	int currentRoom;

};

class Item
{
protected:

	string itemName;
	string itemDescription;

public:

	Item() // default constructor
	{
		itemName = "Nothing";
		itemDescription = " ";
	}

	Item(string name, string desc)
	{
		itemName = name;
		itemDescription = desc;
	}

	string getName() { return itemName; }

	string getDescription() { return itemDescription; }

	virtual void Use()
	{
		cout << "You can't use this item.\n\n";
	}
};

class Key : public Item
{
public:

	Key() : Item("Rusty Key","Maybe it unlocks some kind of door?") {}

	void Use() override
	{
		cout << "You use the Rusty Key..." << endl;
		cout << "The lock clicks!" << endl;
	}
};

class Code : public Item
{
public:

	Code() : Item("East Door Code", "It's the code to the East Room.") {}

	void Use() override
	{
		cout << "You insert the East Door Code...\nThe lock beeps and clicks, and the door creaks open!\n\n";
	}
};

class Room
{
private:

	int north;
	int south;
	int east;
	int west;

public:

	string roomName;
	string roomDescription;
	Item roomItem;
	bool isLocked;
	bool inspected;
	bool visited;

	Room(); // default constructor

	Room(string roomName, string roomDescription); // custom constructor

	Room(string roomName, string roomDescription, int setNorth, int setSouth, int setEast, int setWest);

};

class Locations
{
public:

	Locations();
	Locations(int size);
	Room rooms[5];
};

class Player : public Entity
{
public:

	Player();
	void playGame();
	void showHelp();

	Locations locations;

	Item inventory[5]; // max inventory space
	int itemCount; // how many inventory slots are filled

	void pickUpItem();
	void showInventory();
	void useItem();

};


