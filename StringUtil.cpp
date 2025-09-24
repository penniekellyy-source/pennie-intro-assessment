#include "StringUtil.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int stringUtil::length(string str)
{
	return str.length();
}

stringUtil::stringUtil()
{

}

char stringUtil::characterAt(string str, int index)
{
	return str[index - 1];
}



// StringUtil Function Definitions