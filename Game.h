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
		itemDescription = "There is nothing of use here.";
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
		cout << "You can't use this item." << endl;
	}
};

class Key : public Item
{
public:

	Key() : Item("Rusty Key","An old, rusty key.") {}

	void Use() override
	{
		cout << "You use the Rusty Key." << endl;
		cout << "The lock clicks!" << endl;
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

	Room(); // default constructor

	Room(string roomName, string roomDescription); // custom constructor

	Room(string roomName, string roomDescription, int setNorth, int setSouth, int setEast, int setWest);

};

class Locations
{
public:

	Locations();
	Locations(int size);
	Room rooms[4];
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


