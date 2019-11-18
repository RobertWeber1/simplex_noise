#include "catch.hpp"
#include <simplex_noise/square_root.h>

TEST_CASE("quare root")
{

	REQUIRE_THAT(
		simplex_noise::square_root(25, 0.00000001),
		Catch::Matchers::WithinAbs(5.0, 0.00000001));
}




