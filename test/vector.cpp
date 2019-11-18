#include "catch.hpp"
#include <simplex_noise/vector.h>
#include <simplex_noise/pretty_print.h>

using namespace simplex_noise;




TEST_CASE("compare")
{
	REQUIRE(Vec<int, 1>{2} == Vec<int, 1>{2});
	REQUIRE(Vec<int, 1>{2} != Vec<int, 1>{1});

	REQUIRE(Vec<int, 2>{1,2} == Vec<int, 2>{1,2});
	REQUIRE(Vec<int, 2>{1,2} != Vec<int, 2>{1,1});

	REQUIRE(Vec<int, 3>{1,2,3} == Vec<int, 3>{1,2,3});
	REQUIRE(Vec<int, 3>{1,2,3} != Vec<int, 3>{1,1,3});
}


TEST_CASE("sum")
{
	REQUIRE(sum(Vec<int, 1>{2}) == 2);
	REQUIRE(sum(Vec<int, 2>{1,2}) == 3);
	REQUIRE(sum(Vec<int, 3>{1,2,3}) == 6);
}

TEST_CASE("operator+")
{
	REQUIRE(Vec<int, 1>{2} + Vec<int, 1>{2} == Vec<int, 1>{4});

	REQUIRE(Vec<int, 2>{1,2} + Vec<int, 2>{1,2} == Vec<int, 2>{2,4});

	REQUIRE(Vec<int, 3>{1,2,3} + Vec<int, 3>{1,2,3} == Vec<int, 3>{2,4,6});

	REQUIRE(Vec<int, 3>{1,2,3} + 7 == Vec<int, 3>{8,9,10});
}

TEST_CASE("operator-")
{
	REQUIRE(Vec<int, 1>{2} - Vec<int, 1>{2} == Vec<int, 1>{0});

	REQUIRE(Vec<int, 2>{1,2} - Vec<int, 2>{1,2} == Vec<int, 2>{0,0});

	REQUIRE(Vec<int, 3>{1,2,3} - Vec<int, 3>{1,2,3} == Vec<int, 3>{0,0,0});

	REQUIRE(Vec<int, 3>{8,9,10} - 7 == Vec<int, 3>{1,2,3});
}


TEST_CASE("operator*")
{
	REQUIRE(Vec<int, 3>{8,9,10} * 3 == Vec<int, 3>{24,27,30});
}


TEST_CASE("floor")
{
	REQUIRE(floor<size_t>(Vec<float, 3>{1.4, 7.9, 1.7}) == Vec<size_t, 3>{1, 7, 1});
}

