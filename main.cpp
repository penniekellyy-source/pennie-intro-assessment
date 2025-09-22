#include <iostream>
#include "functions.h"
#include "functions.cpp"
using namespace std;

void getResult();
int num1;
int num2;
int main()
{
	getResult();

	cout << "Please enter a number: " << endl;
	cin >> num1;
	cout << "Please enter another number: " << endl;
	cin >> num2;
}
void getResult()
{
	cout << "Addition: " << num1 + num2 << endl;
	cout << "Subtraction: " << num1 - num2 << endl;
	cout << "Multiplication: " << num1 * num2 << endl;
	cout << "Modulus: " << num1 % num2 << endl;
}