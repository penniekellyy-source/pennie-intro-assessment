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

	Player();

	Locations locations;

};
