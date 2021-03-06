// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>


class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) :
		m_x(x), m_y(y), m_z(z)
	{
	}

	// Convert a Point into its negative equivalent
	Point operator- () const;
	//Point operator+ (const Point &a, const Point &b);
	Point operator+ () const;
	// Return true if the point is set at the origin
	bool operator! () const;

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
};

// Convert a Point into its negative equivalent 
Point Point::operator- () const
{
	return Point(-m_x, -m_y, -m_z);
}

Point Point::operator+ () const
{
	return *this;
}
//Point Point::operator+ (const Point &a, const Point &b) 
//{
//	return Point(a.getX + b.getX, a.getY +b.getY, a.getZ + b.getZ);
//}



// Return true if the point is set at the origin, false otherwise
bool Point::operator! () const
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

int main()
{

	std::cout << "Press enter to exit" << std::endl;
	system("pause");
	std::cin.get();


	return 0;
}