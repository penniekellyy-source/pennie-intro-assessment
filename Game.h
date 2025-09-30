#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Room
{
private:

	string name;
	string description;

	int north; 
	int south;
	int east;
	int west;

public:

	Room(); // default constructor

	Room(string name, string description); // custom constructor

	void enterRoom() const; // const to make sure room name can't be accidentally changed
};

