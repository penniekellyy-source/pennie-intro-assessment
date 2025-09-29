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


	int north = -1; // since arrays start at 0, -1 means "This room doesn't exist"
	int south = -1;
	int east = -1;
	int west = -1;

public:

	Room(); // default constructor

	Room(string name, string description); // custom constructor

	void enterRoom() const; // const to make sure room name can't be accidentally changed
};