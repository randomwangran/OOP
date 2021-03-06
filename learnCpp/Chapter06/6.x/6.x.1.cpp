// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int countTotalItems(int items[], int length)
{
	int sum(0);
	for (int count = 0; count < length; ++count)
		sum = sum + items[count];
	return sum;
}

int main()
{
	enum class ItemType
	{
		HEALTH_POTIONS,
		TORCHES,
		ARROW
	};

	int numberOfItem[3] = {2,5,10};

	std::cout << "The player has "
		<< countTotalItems(numberOfItem, sizeof(numberOfItem) / sizeof(numberOfItem[0]))
		<< " items."
		<< std::endl;

	system("pause");
    return 0;

} 