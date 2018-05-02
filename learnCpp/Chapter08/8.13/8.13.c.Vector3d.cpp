#include "stdafx.h"
#include "Vector3d.h"
#include "Point3d.h"
#include <iostream>


void Vector3d::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}
