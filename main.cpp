#include <iostream>
#include <string>
#include <fstream>
#include "StringUtil.h"
using namespace std;

int main()
{
	stringUtil obj1("I have a sword");
	stringUtil obj2("sword");
	stringUtil obj3("shield");

	cout << obj1.replacement(obj2, obj3);
	
}
