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
	string newDescription;
	string itemType;

public:

	Item() // default constructor
	{
		itemName = "Nothing";
		itemDescription = "There is nothing of use here.";
		newDescription = "You aren't carrying anything of use!";
		itemType = "None";
	}

	Item(string name, string desc, string newDesc, string type)
	{
		itemName = name;
		itemDescription = desc;
		newDescription = newDesc;
		itemType = type;
	}

	string getName() { return itemName; }

	string getDescription() { return itemDescription; }

	string getNewDescription() { return newDescription; }

	string getType() { return itemType; }

	virtual void Use()
	{
		cout << "You can't use this item." << endl;
	}
};

class Key : public Item
{
public:

	Key() : Item("Rusty Key","An old, rusty key.","A rusty key you picked up earlier.", "Key") {}

	void Use() override
	{
		cout << "You use the Rusty key." << endl;
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


