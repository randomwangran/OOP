#include "stdafx.h"
#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string color = "yellow") : m_color(color)
	{
	}

	std::string getColor() { return m_color; }
};

class Apple: public Fruit
{
public:
	Apple(std::string color) : Fruit(color)
	{
	}

	std::string getName() { return "apple"; }
	
	
};

class Banana : public Fruit
{
public:
	Banana()
	{
	}

	std::string getName() { return "Banana"; }

};



int main()
{

	Apple a("red");
	Banana b;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    //	system("pause");

	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}