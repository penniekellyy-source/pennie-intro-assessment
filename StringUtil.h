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

	string str;
	
	int Length(string str);

	stringUtil();

	stringUtil(string str);

	char characterAt(string str, int index);

	bool equalTo(string str1, string str2);

	string append(string str1, string str2);

	string prepend(string str1, string str2);

	string toLower(string str);

	string toUpper(string str);

	bool find(string str1, string str2);

	bool find(string str1, string str2, int skip);

	string replacement(stringUtil toReplace, stringUtil replacement);

	void readFromConsole();

	void writeToConsole();
	
	bool test_length();

	bool test_characterAt();
	
	bool test_equalTo();

	bool test_append();

	bool test_prepend();

	bool test_toLower();

	bool test_toUpper();

	bool test_find();
	
	bool test_findSkip();

	bool test_replacement();

	void logTestResults();

};

#endif
