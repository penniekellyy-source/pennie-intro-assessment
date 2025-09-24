#include <algorithm>
#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int stringUtil::length()
{
	return myString.length();
}

stringUtil::stringUtil()
{
	myString = " ";
}

stringUtil::stringUtil(string str)
{
	myString = str; 
	cout << "constructor called: " << str << endl; 
}

char stringUtil::characterAt(string str, int index)
{
	return str[index - 1];
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

string stringUtil::append(string str1, string str2)
{
	return str1 + str2;
}

string stringUtil::prepend(string str1, string str2)
{
	return str2 + str1;
}

string stringUtil::toLower(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

string stringUtil::toUpper(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

bool stringUtil::find(string str1, string str2)
{
	int position = str1.find(str2);

	if (position != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool stringUtil::find(string str1, string str2, int skip)
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
void stringUtil::readfromConsole()
{
	cout << myString;
}
void stringUtil::writetoConsole()
{
	string str;
	cin >> str;
	cout << str << endl;
}

string stringUtil::replacement(stringUtil toReplace, stringUtil replacement)
{
	int pos = 0;

	while ((pos = myString.find(toReplace.myString, pos)) >= 0)
	{
		myString.replace(pos, toReplace.myString.length(), replacement.myString);
		pos += replacement.myString.length();
	}
	return myString;
}

// StringUtil Function Definitions