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
	int length(string str);

	stringUtil();

	stringUtil(string s);

	char characterAt(string str, int index);
};

#endif
