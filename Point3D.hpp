#pragma once

#include <iostream>
#include <type_traits>

#include "Color.hpp"

template <typename T=int>
requires std::is_arithmetic_v<T>
struct Point3D
{
	T x,y,z;
	Color color;
	
	void setColor(const Color& col)
	{
		color = col;
	}
	
	// Construct from XYZ & Color
	Point3D(T X=0, T Y=0, T Z=0, const Color& COLOR={})
			: x(X), y(Y), z(Z), color(COLOR) {}
	
	// Default Copy Constructor
	Point3D(const Point3D& pnt) = default;

	// Default Assignment Operator
	Point3D& operator= (const Point3D&) = default;
	
	// Comparison Operators //
	
	bool operator == (const Point3D& rhs) const
	{
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
	}
	
	bool operator < (const Point3D& rhs) const
	{
		return (x < rhs.x) || (y < rhs.y) || (z < rhs.z);
	}
	
	bool operator > (const Point3D& rhs) const
	{
		return (x > rhs.x) || (y > rhs.y) || (z > rhs.z);
	}
	
	bool operator << (const Point3D& rhs) const
	{
		return (x < rhs.x) && (y < rhs.y) && (z < rhs.z);
	}
	
	bool operator >> (const Point3D& rhs) const
	{
		return (x > rhs.x) && (y > rhs.y) && (z > rhs.z);
	}
	
	// Arithmatic Operators //

	template <typename T2>
	Point3D<T> operator + (const Point3D<T2>& rhs)
	{
		return {x + rhs.x, y + rhs.y, z + rhs.z};
	}
	/*
	Point3D operator - (const Point3D<auto>& rhs)
	{
		return {x - rhs.x, y - rhs.y, z - rhs.z};
	}
	
	Point3D operator * (const Point3D<auto>& rhs)
	{
		return {x * rhs.x, y * rhs.y, z * rhs.z};
	}
	
	Point3D operator / (const Point3D<auto>& rhs)
	{
		return {x / rhs.x, y / rhs.y, z / rhs.z};
	}*/
};
