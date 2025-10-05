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

public:

	Item() // default constructor
	{
		itemName = "Nothing";
		itemDescription = "There is nothing of use here.";
		newDescription = "You aren't carrying anything of use!";
	}

	Item(string name, string desc, string newDesc)
	{
		itemName = name;
		itemDescription = desc;
		newDescription = newDesc;
	}

	string getName()
	{
		return itemName;
	}

	string getDescription()
	{
		return itemDescription;
	}

	string getNewDescription()
	{
		return newDescription;
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

};


