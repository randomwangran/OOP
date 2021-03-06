// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cstdint> // for fixed width integers
#include <cmath>

class FixedPoint2
{
private:
	std::int16_t m_base; // here's our non-fractional part
	std::int8_t m_decimal; // here's our factional part
	double temp = 0.0;
public:
	FixedPoint2(std::int16_t base = 0, int8_t decimal = 0)
		: m_base(base), m_decimal(decimal)
	{
		// We should handle the case where decimal is > 99 or < -99 here
		// but will leave as an exercise for the reader

		// If either the base or decimal or negative
		if (m_base < 0.0 || m_decimal < 0.0)
		{
			// Make sure base is negative
			if (m_base > 0.0)
				m_base = -m_base;
			// Make sure decimal is negative
			if (m_decimal > 0.0)
				m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double inputDouble)
	{
		m_base = static_cast<int16_t>(round(inputDouble));
		m_decimal = static_cast<int8_t>(round((inputDouble - m_base)*100));
		
	}

	~FixedPoint2()
	{
	}

	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100;
	}

	friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp)
	{
		out << static_cast<double>(fp);
		return out;
	}

	friend bool operator== (const FixedPoint2 &pintA, const FixedPoint2 &pintB);
	friend FixedPoint2 operator+ (const FixedPoint2 &pointA, const FixedPoint2 &pointB);
	friend FixedPoint2 operator- (const FixedPoint2 &point);
	friend std::istream& operator>> (std::istream &in, FixedPoint2 &point);
	double getIni() 
	{
		double number;
		std::cin >> number;
		return number;
	}
};

bool operator== (const FixedPoint2 &pointA, const FixedPoint2 &pointB)
{
	return (pointA.m_base == pointB.m_base && pointA.m_decimal == pointB.m_decimal);
}

FixedPoint2 operator+ (const FixedPoint2 &pointA, const FixedPoint2 &pointB)
{
	return FixedPoint2(pointA.m_base + pointB.m_base + static_cast<double>(pointA.m_decimal + pointB.m_decimal)/100);
}

FixedPoint2 operator- (const FixedPoint2 &point)
{
	return FixedPoint2(-point.m_base, -point.m_decimal);
}

std::istream& operator>> (std::istream &in, FixedPoint2 &point)
{
    //FixedPoint2(0.0);
	// I cannot overload operator>>. For the simple case, we can just
	// in >> point.m_variables
	// However, in this case, we need to let the instance of FixedPoint2
	// to access the constructor, which I do not know hwo to implyment.

    // I read the hint from Alex, but "by creating an anonymous object of
	// of type FixedPoint2" does not give me too much information here.
	return in;	
}


void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';
	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n'; // fail to implyment this function overloading.

	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}