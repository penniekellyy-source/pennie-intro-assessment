#include <iostream>
#include <string>
#include <fstream>
#include "StringUtil.h"

using namespace std;

int main()
{
	stringUtil myStringUtil("Hello World!");
	cout << " " << endl;

	stringUtil testString;

	testString.test_length();

	testString.test_characterAt();

	testString.test_equalTo();

	testString.test_append();

	testString.test_prepend();

	testString.test_toLower();

	testString.test_toUpper();

	testString.test_find();
	
	testString.test_findSkip();

	testString.test_replacement();

	cout << "Read from console : " << endl;
	testString.readFromConsole();
	cout << " " << endl;
	cout << " " << endl;

	cout << "Write to console : " << endl;
	testString.writeToConsole();

	testString.logTestResults();
	
}
