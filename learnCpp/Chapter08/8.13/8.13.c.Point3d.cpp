#include "stdafx.h"
#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>


void Point3d::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}


void Point3d::moveByVector(const Vector3d &v)
{
	m_x = m_x + v.m_x;
	m_y = m_y + v.m_y;
	m_z = m_z + v.m_z;
}