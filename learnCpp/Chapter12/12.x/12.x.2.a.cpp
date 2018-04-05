#include "stdafx.h"
#include <string>
#include <iostream>

class Shape
{
public:
	virtual std::ostream& print(std::ostream &out) const = 0;
	friend std::ostream& operator<< (std::ostream &out, const Shape &shape)
        {
	  return shape.print(out);
	}
	virtual ~Shape()
	{
	}
};

int main()
{


	system("pause");

	return 0;

}
