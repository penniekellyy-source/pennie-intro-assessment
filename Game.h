#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Room
{
private:

	string roomName;
	string roomDescription;

	int north; 
	int south;
	int east;
	int west;

public:

	Room(); // default constructor

	Room(string roomName, string roomDescription); // custom constructor

	void enterRoom() const; // const to make sure room name can't be accidentally changed

};
void roomSetup(Room rooms[], int size);
void playGame(Room rooms[], int size);
