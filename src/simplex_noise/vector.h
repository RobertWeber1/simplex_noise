#pragma once
#include <utility>


namespace simplex_noise
{


template<class T, size_t N>
struct Vec
{
	T data[N];

	T const& operator[](size_t i) const
	{
		return data[i];
	}

	T& operator[](size_t i)
	{
		return data[i];
	}

	template<class OTHER>
	operator Vec<OTHER, N>() const
	{
		Vec<OTHER, N>{data};
	}
};


namespace detail
{

template<class T, size_t N, size_t ... Ns>
Vec<T, N> plus(Vec<T, N> const& a, Vec<T, N> const& b, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] + b[Ns]) ...};
}

template<class T, size_t N, size_t ... Ns>
Vec<T, N> plus(Vec<T, N> const& a, T s, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] + s) ...};
}

//------------------------------------------------------------------------------

template<class T, size_t N, size_t ... Ns>
Vec<T, N> minus(Vec<T, N> const& a, Vec<T, N> const& b, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] - b[Ns]) ...};
}

template<class T, size_t N, size_t ... Ns>
Vec<T, N> minus(Vec<T, N> const& a, T s, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] - s) ...};
}

//------------------------------------------------------------------------------

template<class T, size_t N, size_t ... Ns>
Vec<T, N> mult(Vec<T, N> const& a, Vec<T, N> const& b, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] * b[Ns]) ...};
}

template<class T, size_t N, size_t ... Ns>
Vec<T, N> mult(Vec<T, N> const& a, T s, std::index_sequence<Ns...> const&)
{
	return {(a[Ns] * s) ...};
}

//------------------------------------------------------------------------------

template<class T, size_t N, size_t ... Ns>
bool equal(Vec<T, N> const& a, Vec<T, N> const& b, std::index_sequence<Ns...> const&)
{

	return (... and (a[Ns] == b[Ns]));
}

template<class T, size_t N, size_t ... Ns>
T sum(Vec<T, N> const& v, std::index_sequence<Ns...> const&)
{
	return (... + v[Ns]);
}


template<class T, size_t N, size_t ... Ns>
T sub(Vec<T, N> const& v, std::index_sequence<Ns...> const&)
{
	return (... - v[Ns]);
}


template<class R, class T, size_t N, size_t ... Ns>
Vec<R, N> floor(Vec<T, N> const& v, std::index_sequence<Ns...> const&)
{
	return {static_cast<R>(((v[Ns])>0) ? static_cast<int>(v[Ns]) : static_cast<int>(v[Ns])-1) ...};
}


template<class R, class T, size_t N, size_t ... Ns>
Vec<R, N> mask(Vec<T, N> const& a, R mask, std::index_sequence<Ns...> const&)
{
	return {static_cast<R>(a[Ns] & mask) ...};
}


} //namespace detail


template<class T, size_t N>
Vec<T, N> operator+(Vec<T, N> const& a, Vec<T, N> const& b)
{
	return detail::plus(a, b, std::make_index_sequence<N>{});
}

template<class T, size_t N>
Vec<T, N> operator+(Vec<T, N> const& a, T s)
{
	return detail::plus(a, s, std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------------

template<class T, size_t N>
Vec<T, N> operator-(Vec<T, N> const& a, Vec<T, N> const& b)
{
	return detail::minus(a, b, std::make_index_sequence<N>{});
}

template<class T, size_t N>
Vec<T, N> operator-(Vec<T, N> const& a, T s)
{
	return detail::minus(a, s, std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------------

template<class T, size_t N>
Vec<T, N> operator*(Vec<T, N> const& a, Vec<T, N> const& b)
{
	return detail::mult(a, b, std::make_index_sequence<N>{});
}

template<class T, size_t N>
Vec<T, N> operator*(Vec<T, N> const& a, T s)
{
	return detail::mult(a, s, std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------------

template<class T, size_t N>
bool operator==(Vec<T, N> const& a, Vec<T, N> const& b)
{
	return detail::equal(a, b, std::make_index_sequence<N>{});
}


template<class T, size_t N>
bool operator!=(Vec<T, N> const& a, Vec<T, N> const& b)
{
	return not detail::equal(a, b, std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------------

template<class T, size_t N>
T sum(Vec<T, N> const& v)
{
	return detail::sum(v, std::make_index_sequence<N>{});
}

template<class T, size_t N>
T sub(Vec<T, N> const& v)
{
	return detail::sub(v, std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------------

template<class R, class T, size_t N, size_t ... Ns>
Vec<R, N> floor(Vec<T, N> const& v)
{
	return detail::floor<R>(v, std::make_index_sequence<N>{});
}


template<class R, class T, size_t N>
Vec<R, N> mask(Vec<T, N> const& a, R mask)
{
	return detail::mask(a, mask, std::make_index_sequence<N>{});
}



} //namespace simplex_noise
