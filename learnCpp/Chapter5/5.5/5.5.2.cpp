// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    
	int count = 1;

	int aASCII = 'a';

	while (count < 27)
	{
		std::cout << char(aASCII) << " its ASCII code is: " << aASCII << std::endl;
		count++;
		aASCII++;
	}

	system("pause");

    return 0;

} 