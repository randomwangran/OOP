// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


struct myData {
	int a;
	int b;
};

myData swap(myData &a)
{
	int temp;
	temp = a.b;
	a.b = a.a;
	a.a = temp;

	return a;
}
int main()
{

	myData test = { 1,2 };

	std::cout << "Before sorted:" << test.a << " " << test.b << std::endl;

	swap(test);

	std::cout << "After sorted:" << test.a << " " << test.b << std::endl;

	system("pause");
	return 0;

}