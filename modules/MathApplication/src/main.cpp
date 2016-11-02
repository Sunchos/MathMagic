#include "pch.h"
#include "MathFunctions.h"

int main()
{
	double dd = 0.0;
	std::cout << "Set the parameter a side: ";
	std::cin >> dd;

	std::cout << "Square Triangle is: " << TriangleArea(dd) << std::endl;
	return 0;
}