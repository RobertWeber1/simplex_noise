#pragma once
#include <simplex_noise/square_root.h>

namespace simplex_noise
{

template<size_t N>
struct F
{
	static const float value;
};

template<size_t N>
const float F<N>::value = (std::sqrt(N + 1) - 1) / N;


template<size_t N>
struct G
{
	static const float value;
};

template<size_t N>
const float G<N>::value = (1 - (1 / std::sqrt(N + 1))) / N;


} //namespace simplex_noise
