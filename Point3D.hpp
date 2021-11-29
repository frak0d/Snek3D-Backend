#pragma once

#include "Color.hpp"

template <typename T=int> struct Point3D
{
	T x,y,z;
	Color color;
	
	void setColor(const Color& col)
	{
		color = col;
	}
	
	Color getColor()
	{
		return color;
	}
	
	// Construct from XYZ & Color
	Point3D(T X=0, T Y=0, T Z=0, const Color& col={})
	{
		x = X;
		y = Y;
		z = Z;
		color = col;
	}
	
	// Construct from a Point3D Object
	Point3D(const Point3D& pnt)
	{
		x = pnt.x;
		y = pnt.y;
		z = pnt.z;
		color = pnt.color;
	}
	
	// Comparison Operators //
	
	bool operator == (const Point3D& rhs)
	{
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
	}
	bool operator < (const Point3D& rhs)
	{
		return (x < rhs.x) && (y < rhs.y) && (z < rhs.z);
	}
	bool operator > (const Point3D& rhs)
	{
		return (x > rhs.x) || (y > rhs.y) || (z > rhs.z);
	}
	
	// Arithmatic Operators //
	
	Point3D operator + (const Point3D& rhs)
	{
		return {x + rhs.x, y + rhs.y, z + rhs.z};
	}
	Point3D operator - (const Point3D& rhs)
	{
		return {x - rhs.x, y - rhs.y, z - rhs.z};
	}
	
	Point3D operator * (const Point3D& rhs)
	{
		return {x * rhs.x, y * rhs.y, z * rhs.z};
	}
	
	Point3D operator / (const Point3D& rhs)
	{
		return {x / rhs.x, y / rhs.y, z / rhs.z};
	}
};