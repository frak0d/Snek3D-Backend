#pragma once

#include <string>
#include <stdint.h>

struct Color
{
	uint8_t r,g,b,a;
	
	// Construct from RGBA Values
	Color(uint8_t R=0, uint8_t G=0,
				uint8_t B=0, uint8_t A=255)
	{
		r = R;
		g = G;
		b = B;
		a = A;
	}
	
	// Construct from Hex Values
	Color(std::string hex)
	{
		if (hex[0] == '#'); // WIP
		r = std::stoul(hex, 0, 16);
		g = std::stoul(hex, 0, 16);
		b = std::stoul(hex, 0, 16);
		a = std::stoul(hex, 0, 16);
	}
	
	// Construct from a Color Object
	Color(const Color& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
		a = col.a;
	}
};