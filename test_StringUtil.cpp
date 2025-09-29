#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool stringUtil::test_length()
{

	if (Length(str) == str.length())
	{
		cout << "length() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "length() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_characterAt()
{
	int character = 5;

	if (characterAt(str, character) == str[character - 1])
	{
		cout << "characterAt() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "characterAt() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_equalTo() 
{
	string str1 = "Hello";
	string str2 = "Hello";

	if (equalTo(str1, str2) == (str1 == str2))
	{
		cout << "equalTo() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "equalTo() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_append() 
{
	string str1 = "Hello";

	string str2 = "World";

	if (append(str1, str2) == (str1 + str2))
	{
		cout << "append() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "append() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_prepend()
{
	string str1 = "Hello";

	string str2 = "World";

	if (prepend(str1, str2) == (str2 + str1))
	{
		cout << "prepend() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "prepend() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_toLower()
{
	string str = "TESTING FUNCTION";

	if (toLower(str) == ("testing function"))
	{
		cout << "toLower() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "toLower() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_toUpper()
{
	string str = "testing function";

	if (toUpper(str) == ("TESTING FUNCTION"))
	{
		cout << "toUpper() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "toUpper() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_find()
{
	string str1 = "Testing Function";
	string str2 = "Function";

	if (find(str1, str2) == (str1.find(str2) != string::npos))
	{
		cout << "find() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "find() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

bool stringUtil::test_findSkip()
{
	string str1 = "Testing Function";
	string str2 = "Function";
	int skip = 5;

	if (find(str1, str2, skip) == (str1.find(str2, skip) != string::npos))
	{
		cout << "findSkip() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "find() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}

}

bool stringUtil::test_replacement()
{
	myString = "String test";

	stringUtil toReplace;
	toReplace.myString = "test";

	stringUtil replace;
	replace.myString = "class";

	if (replacement(toReplace, replace) == "String class")
	{
		cout << "test_replacement() function : passed!" << endl;
		cout << " " << endl;
		return true;
	}
	else
	{
		cout << "test_replacement() function : failed!" << endl;
		cout << " " << endl;
		return false;
	}
}

void stringUtil::logTestResults()
{
	ofstream logFile("test_log.txt", ios::app);

	if (logFile.is_open())
	{
		stringUtil stringTest;

		logFile << "Date: " << __DATE__ << endl;
		logFile << "  Time: " << __TIME__ << endl << endl;

		if (stringTest.test_length())
		{
			logFile << "test_length() : passed" << endl;
		}
		else
		{
			logFile << "test_length() : failed" << endl;
		}
		if (stringTest.test_characterAt())
		{
			logFile << "test_length() : passed" << endl;
		}
		else
		{
			logFile << "test_length() : failed" << endl;
		}
		if (stringTest.test_equalTo())
		{
			logFile << "test_equalTo() : passed" << endl;
		}
		else
		{
			logFile << "test_equalTo() : failed" << endl;
		}
		if (stringTest.test_append())
		{
			logFile << "test_append() : passed" << endl;
		}
		else
		{
			logFile << "test_append() : failed" << endl;
		}
		if (stringTest.test_prepend())
		{
			logFile << "test_prepend() : passed" << endl;
		}
		else
		{
			logFile << "test_prepend() : failed" << endl;
		}
		if (stringTest.test_toLower())
		{
			logFile << "test_toLower() : passed" << endl;
		}
		else
		{
			logFile << "test_toLower() : failed" << endl;
		}
		if (stringTest.test_toUpper())
		{
			logFile << "test_toUpper() : passed" << endl;
		}
		else
		{
			logFile << "test_toUpper() : failed" << endl;
		}
		if (stringTest.test_find())
		{
			logFile << "test_find() : passed" << endl;
		}
		else
		{
			logFile << "test_find() : failed" << endl;
		}
		if (stringTest.test_findSkip())
		{
			logFile << "test_findSkip() : passed" << endl;
		}
		else
		{
			logFile << "test_findSkip() : failed" << endl;
		}
		if (stringTest.test_replacement())
		{
			logFile << "test_replacement() : passed" << endl;
		}
		else
		{
			logFile << "test_replacement() : failed" << endl;
		}
		logFile.close();
			
		cout << "Test results logged successfully!" << endl;
	}
	else
	{
		cout << "ERROR! Could not write to log file!" << endl;
	}
}

