#pragma once
#include <simplex_noise/vector.h>
#include <ostream>


namespace simplex_noise
{


template<class T, size_t N>
std::ostream & operator<<(std::ostream & os, Vec<T, N> const& vec)
{
	os << "{";
	for(size_t i = 0; i < N; ++i)
	{
		if(i != 0)
		{
			os << ", ";
		}
		os << vec[i];
	}

	return os << "}";
}


} //namespace simplex_noise
