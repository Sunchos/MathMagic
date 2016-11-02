#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "MathFunctions.h"

BOOST_AUTO_TEST_SUITE(triangle)

BOOST_AUTO_TEST_CASE(squareTest1)
{
	if (TriangleArea(4) != 6)
		BOOST_ERROR("Square equals: " + std::to_string(TriangleArea(4)));
}

BOOST_AUTO_TEST_CASE(squareTest2)
{
	if (TriangleArea(-4) != 6)
		BOOST_ERROR("Square equals: " + std::to_string(TriangleArea(-4)));
}

BOOST_AUTO_TEST_CASE(squareTest3)
{
	if (TriangleArea(-4) != 6)
		BOOST_ERROR("Square equals: " + std::to_string(TriangleArea(-4)));
}

BOOST_AUTO_TEST_SUITE_END()