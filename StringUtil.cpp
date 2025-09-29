#include <algorithm>
#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

stringUtil::stringUtil()
{
	myString = " "; // if no text is provided, start with blank string
	str = "Hello World!";
}

stringUtil::stringUtil(string str)
{
	myString = str;
	cout << str << endl;
}

int stringUtil::Length(string str) 
{
	return str.length();
}

char stringUtil::characterAt(string str, int index) // takes text and number as input, gives back one character
{
	return str[index - 1]; // subtracts 1 so user can ask for characters starting from 1
}

bool stringUtil::equalTo(string str1, string str2)
{
	if (str1 == str2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string stringUtil::append(string str1, string str2) // takes two strings, adds them, displays result
{
	return str1 + str2;
}

string stringUtil::prepend(string str1, string str2) // does the same thing but puts second string first
{
	return str2 + str1;
}

string stringUtil::toLower(string str)
{
	for (int i = 0; i < str.length(); i++) // starts at the first character, continues until end of string
	{
		str[i] = tolower(str[i]); // takes character at position i, converts to lowercase, puts it back
	}
	return str;
}

string stringUtil::toUpper(string str)
{
	for (int i = 0; i < str.length(); i++) 
	{
		str[i] = toupper(str[i]); // takes character at position i, converts to uppercase, puts it back
	}
	return str;
}

bool stringUtil::find(string str1, string str2)
{
	int position = str1.find(str2); // searches through str1 to find first occurrance of str2
	// if found, returns index where str2 begins inside str1, otherwise returns npos

	if (position != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool stringUtil::find(string str1, string str2, int skip) // string to search in, substring to look for, int specifying starting position
// basically, look for str2 inside str but start at position skip instead of the beginning
{
	int position = str1.find(str2, skip); 

	if (position != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string stringUtil::replacement(stringUtil toReplace, stringUtil replacement) // keep looping until toReplace is found in myString starting from position pos
{
	int pos = 0;

	while ((pos = myString.find(toReplace.myString, pos)) >= 0)
	{
		myString.replace(pos, toReplace.myString.length(), replacement.myString); // starts at position pos, replaces text that matches toReplace with replacement
		pos += replacement.myString.length(); // moves pos forward to avoid re-checking the same part that was replaced
	}
	return myString;
}

void stringUtil::readFromConsole()
{
	cout << myString;
}

void stringUtil::writeToConsole()
{
	string str;
	cin >> str;
	cout << str << endl;
}

// StringUtil Function Definitions