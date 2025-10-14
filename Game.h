#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Entity
{
protected:

	int entityAttack;
	int entityHealth;
	string entityName;

public:

	int currentRoom;

	Entity()
	{
		entityName = "Unknown";
		entityHealth = 100;
		entityAttack = 10;
		currentRoom = 0;
	}

	Entity(string name, int health, int attack)
	{
		entityName = name;
		entityHealth = health;
		entityAttack = attack;
		currentRoom = 0;
	}

	string getEntityName() { return entityName; }

	int getEntityHealth() { return entityHealth; }

	int getEntityAttack() { return entityAttack; }

	void takeDamage(int damage)
	{
		entityHealth -= damage;
		if (entityHealth < 0) entityHealth = 0;
	}

	bool isDead()
	{
		return entityHealth <= 0;
	}
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

	string getItemName() { return itemName; }

	string getItemDescription() { return itemDescription; }

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

class Enemy : public Entity
{
public:

	bool isDefeated;

	Enemy() : Entity("Unknown", 100, 10)
	{
		isDefeated = false;
	}

	Enemy(string name, int health, int attack) : Entity(name, health, attack)
	{
		isDefeated = false;
	}

	void defeat()
	{
		isDefeated = true;
	}
};

class Room
{
private:


public:

	int north;
	int south;
	int east;
	int west;

	string roomName;
	string roomDescription;
	Item roomItem;

	bool isLocked;
	bool inspected;
	bool visited;

	Enemy roomEnemy;
	bool hasEnemy;

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

	Player() : Entity("Player", 100, 10)
	{
		itemCount = 0;
		currentRoom = 0;
	}

	Item inventory[5]; // max inventory space
	int itemCount; // how many inventory slots are filled

	Locations locations;

	void playGame();
	void showHelp();
	void pickUpItem();
	void showInventory();
	void useItem();
};


