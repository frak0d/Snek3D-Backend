#pragma once

#include <random>
#include "Point3D.hpp"

template <typename T>
Point3D<T> rand_coord(const Point3D<T>& low_lim, const Point3D<T>& up_lim)
{
	std::random_device r;   // these 2 lines can be moved outside
	std::mt19937 rand(r()); // the fuction to increase performance
	
	std::uniform_real_distribution<T> xgen(low_lim.x, up_lim.x);
	std::uniform_real_distribution<T> ygen(low_lim.y, up_lim.y);
	std::uniform_real_distribution<T> zgen(low_lim.z, up_lim.z);
	
	T x = xgen(rand);
	T y = ygen(rand);
	T z = zgen(rand);
	
	return {x,y,z};
}