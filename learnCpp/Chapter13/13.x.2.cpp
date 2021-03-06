#include "stdafx.h"
#include <string>
#include <iostream>

template <typename Ta, typename Tb>
class Pair
{
private:
	Ta m_a;
	Tb m_b;

public:
	Pair(Ta a, Tb b) : m_a(a), m_b(b)
	{
	}

	Ta first()
	{
		return m_a;
	}

	Tb second()
	{
		return m_b;
	}

	Ta first() const
	{
		return m_a;
	}

	Tb second() const
	{
		return m_b;
	}

};

int main()
{

	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';


	system("pause");
	return 0;

}