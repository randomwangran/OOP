// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cassert>

class IntArray
{
	int m_size;
	int *m_array = new int[m_size];


public:
	IntArray(int size = 0) : m_size(size) {
		int *m_array = new int[m_size];

	}

	friend std::ostream& operator<< (std::ostream &out, const IntArray &array);

	int& operator[] (const int index)
	{
		return m_array[index];
	}
};


std::ostream& operator<< (std::ostream &out, const IntArray &array)
{
	out;

	for (int count = 0; count < array.m_size; ++count)
	{
		std::cout << array.m_array[count] << " ";
	}
	
	return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}




int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';



	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}