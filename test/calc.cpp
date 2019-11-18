#include "catch.hpp"
#include "simplex_noise/calc.h"

using namespace simplex_noise;

TEST_CASE("calculate distances to simplex corners")
{
	std::cout << calc(Vec<float, 2>{1.5, 1.5}) << "\n";
	// REQUIRE(1==2);
}