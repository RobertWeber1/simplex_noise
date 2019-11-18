#pragma once
#include <stddef.h>

#include <iostream>
#include <iomanip>

namespace simplex_noise
{


constexpr double square_root(double x, double max_error = 0.00000001)
{
	if (x<=0)
	{
		return 0;

	}

	double xhi = x;
	double xlo = 0;
	double guess = x/2;

	while (std::abs(guess*guess-x) > max_error )
	{
		if (guess*guess > x){
			xhi = guess;
		}
		else {
			xlo = guess;
		}
		guess = (xhi + xlo)/2;
	}
	return guess;
}

} //namespace simplex_noise