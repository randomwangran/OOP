// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <string>

void printString(char *ptr, int length)
{
	for (char *oneByone = ptr; oneByone <= ptr + length; ++oneByone)
	{
		std::cout << *oneByone << std::endl;
		if (*oneByone == '\0')
			break;
	}
		
}
int main()
{
	const int testArrayLength = 14;
	char testArray[] = "Hello, World!";

	printString(testArray, testArrayLength);

	system("pause");
	return 0;

}