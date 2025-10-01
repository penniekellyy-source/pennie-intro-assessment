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

	Room(); // default constructor

	Room(string roomName, string roomDescription); // custom constructor

	Room(string roomName, string roomDescription, int setNorth, int setSouth, int setEast, int setWest);

};

class Locations : Room
{
public:

	Locations();
	Locations(int size);
	Room rooms[4];
};

class Player : Entity
{
public:

	void playGame();

	void showHelp();

	Player();

	Locations locations;

};

class Item
{
protected:

	string itemName;
	string itemDescription;

public:

	Item(string name, string desc)
	{
		name = itemName;
		desc = itemDescription;
	}
};

class item : Item // all placeholder names till I get it working
{
public:

	item() : Item("Item name", "Item description") {}
	void use()
	{
		cout << "This is what the item does!" << endl;
	}

};