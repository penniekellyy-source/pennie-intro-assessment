#include <iostream>
using namespace std;

//void continueloop()
//{
//	char choice;
//
//	do
//	{
//		cout << "this is inside the do-while loop!" << endl;
//		cout << "would you like to continue? (y/n): ";
//		cin >> choice;
//		cout << endl;
//
//	} while (choice == 'y' || choice == 'y');
//	{
//		cout << "loop has ended." << endl;
//	}
//}
//void countdowntimer()
//{
//	int num = 10;
//	
//	while (num >= 0)
//	{
//		cout << num << endl;
//		num = num - 1;
//	}
//	cout << "launching..." << endl;
//}
//
//void getnumber()
//{
//	int number = 0;
//	cout << "please enter a positive number that is greater than 0." << endl;
//	cin >> number;
//
//	while (number < 0)
//	{
//		cout << "please enter a positive number that is greater than 0." << endl;
//		cin >> number;
//	}
//	if (number >= 0)
//	{
//		cout << "thank you!" << endl;
//	}
//}
//
//void numbersum()
//{
//	int sum = 0;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		sum = sum + i;
//	}
//	cout << sum;
//}
//void getnumber()
//{
//
//	for (int i = 1; i <= 12; i++)
//	{
//		if (number > 12) 
//		{
//			cout << "invalid!" << endl;
//		}
//		else
//		{
//			cout << i << " * " << number << " = " << i * number << endl;
//		}
//		
//	}
//
//	
//}
//
//void getnumbers()
//{
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << i << endl;
//	}
//}
//void getnumberseven()
//{
//	for (int i = 2; i <= 20; i++)
//	{
//		
//		if (i % 2 == 0)
//		{
//			cout << i << endl;
//		}
//		
//
//	}
//}
//void printarray()
//{
//	int arr[5] = { 0, 1, 2, 3, 4 };
//	arr[0] = 10;
//	arr[4] = 50;
//	cout << arr[0] << ", " << arr[4];
//}
//void printvalue()
//{
//	const int max_size = 4;
//
//	int numbers[4] = { 5, 10, 15, 20 };
//	cout << "the value of this element is: " << numbers[1] << endl;
//	cout << "the length of this array is: " << max_size << endl;
//
//}
//void printloop()
//{
//	int numbers[3] = { 7, 14, 21 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << i << " = " << numbers[i] << endl;
//	}
//}
//void printstring()
//{
//	string playername;
//	cout << "what is your name?" << endl;
//	cin >> playername;
//
//	cout << "name inputted: " << playername << endl;
//	cout << "length of string: " << playername.length() << endl;
//	cout << "first character: " << playername[0] << endl;
//}
//void stringFunction(string color)
//{
//	cout << color << endl;
//}
//bool equalTo(string leng1, string leng2)
//{
//	cout << "Are these strings equal?" << endl;
//	if (leng1 == leng2)
//	{
//		return (true);
//	}
//	else
//	{
//		return (false);
//	}
//
//}
//int getLength(string leng)
//{
//	cout << "Insert a word: " << endl;
//	cin >> leng;
//	cout << "The length of this string is: " << leng.length() << endl;
//	return leng.length();
//}
//
//
//int getLength(string leng)
//{
//	cout << "Insert a word: " << endl;
//	cin >> leng;
//	cout << "The length of this string is: " << leng.length() << endl;
//	return leng.length();
//}
//
//
//
//bool equalTo(string leng1, string leng2)
//{
//	cout << "Are these strings equal?" << endl;
//	if (leng1 == leng2)
//	{
//		return (true);
//	}
//	else
//	{
//		return (false);
//	}
//
//}
//string convertLower(string cmd)
//{
//	for (int i = 1; i < cmd.length(););
//	{
//		if (cmd[i] >= 'A' && cmd[i] <= 'Z')
//		{
//			cmd[i] = cmd[i] + 32;
//		}
//	}
//	cout << "The entered character in lowercase is: " << cmd << endl;
//	return cmd;
//}
//string converLower(string cmd)
//{
//	for (int i = 1; i < cmd.length(););
//	{
//		if (cmd[i] >= 'a' && cmd[i] <= 'z')
//		{
//			cmd[i] = cmd[i] - 32;
//		}
//	}
//	cout << "The entered character in uppercase is: " << cmd << endl;
//	return cmd;
//}	
