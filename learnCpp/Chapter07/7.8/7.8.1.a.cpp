// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int userIntInput()
{
	std::cout << "Enter a integer:" << std::endl;
	int a;
	std::cin >> a;
	return a;
}

char userCharInput()
{
	char a;

	do
	{
		std::cout << "Enter a mathematical operation ('+','-','*','/')";
		std::cin >> a;
	} while (!(a == '+' || a == '-' || a == '*' || a == '/'));

	return a;
}
int main()
{
	userIntInput();
	userCharInput();
	userIntInput();
	
	system("pause");
	return 0;

}