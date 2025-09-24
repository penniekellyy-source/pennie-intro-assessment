#ifndef STRINGUTIL_H
#define STRINGUTIL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class stringUtil
{
private: 
	string myString;

public:
	int length();

	stringUtil();

	stringUtil(string str);

	char characterAt(string str, int index);

	bool equalTo(string str, string str2);

	string append(string str1, string str2);

	string prepend(string str1, string str2);

	string toLower(string str);

	string toUpper(string str);

	bool find(string str1, string str2);

	bool find(string str1, string str2, int skip);

	void readfromConsole();

	void writetoConsole();

	string replacement(stringUtil toReplace, stringUtil replacement);
};

#endif
