#pragma once
#include <math.h>
#include <iostream>

inline int TriangleArea(double sideTriangle)
{
	return static_cast<int>(((sqrt(3)) * pow(sideTriangle, 2)) / 4);
}