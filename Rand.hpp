#pragma once

#include <random>
#include <concepts>
#include "Point3D.hpp"

std::random_device rndm_dev;   // these 2 lines are outside the
std::mt19937 rndm_mt(rndm_dev()); // fuction to increase performance

template <typename T> requires std::floating_point<T> || std::integral<T>
Point3D<T> rand_coord(const Point3D<T>& low_lim, const Point3D<T>& up_lim, const Color& col={})
{
	if constexpr (std::is_floating_point_v<T>)
	{
		std::uniform_real_distribution<T> xgen(low_lim.x, up_lim.x);
		std::uniform_real_distribution<T> ygen(low_lim.y, up_lim.y);
		std::uniform_real_distribution<T> zgen(low_lim.z, up_lim.z);
		
		T x = xgen(rndm_mt);
		T y = ygen(rndm_mt);
		T z = zgen(rndm_mt);
		
		return {x,y,z, col};
	}
	else if constexpr (std::is_integral_v<T>)
	{
		std::uniform_int_distribution<T> xgen(low_lim.x, up_lim.x);
		std::uniform_int_distribution<T> ygen(low_lim.y, up_lim.y);
		std::uniform_int_distribution<T> zgen(low_lim.z, up_lim.z);

		T x = xgen(rndm_mt);
		T y = ygen(rndm_mt);
		T z = zgen(rndm_mt);
		
		return {x,y,z, col};
	}
}
