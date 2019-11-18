#include "catch.hpp"
#include <simplex_noise/squash.h>

using namespace simplex_noise;

TEST_CASE("Squash factor")
{
	REQUIRE_THAT(F<2>::value, Catch::Matchers::WithinAbs(0.366025403f, 0.0000001));
	REQUIRE_THAT(F<3>::value, Catch::Matchers::WithinAbs(0.333333333f, 0.0000001));
	REQUIRE_THAT(F<4>::value, Catch::Matchers::WithinAbs(0.309016994f, 0.0000001));

	REQUIRE_THAT(G<2>::value, Catch::Matchers::WithinAbs(0.211324865f, 0.0000001));
	REQUIRE_THAT(G<3>::value, Catch::Matchers::WithinAbs(0.166666667f, 0.0000001));
	REQUIRE_THAT(G<4>::value, Catch::Matchers::WithinAbs(0.138196601f, 0.0000001));
}