#include "pch.h"
#include "MathFunctions.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation of the Math Magic functions.
//

namespace  mm
{
double TriangleArea(double sideTriangle)
{
	return (((sqrt(3)) * pow(sideTriangle, 2)) / 4);
}
} // namespace mm.