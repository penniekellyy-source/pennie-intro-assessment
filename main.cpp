#include <iostream>

#include <string>
#include <fstream>
#include "StringUtil.h"
using namespace std;

int main()
{
	stringUtil util;
	util.length("Blah");

	cout << util.characterAt("string", 4);

}
