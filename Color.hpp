#pragma once

#include <string>
#include <stdint.h>

struct Color
{
	uint8_t r,g,b,a;
	
	// Construct from RGBA Values
	Color(uint8_t R=0, uint8_t G=0, uint8_t B=0, uint8_t A=255)
		: r(R), g(G), b(B), a(A) {}
	
	// Construct from Hex Values
	Color(std::string hex)
	{
		if (hex[0] == '#')
		{
			hex = std::string(hex.begin()+1, hex.end());
		}; // WIP
		r = std::stoul(hex, 0, 16);
		g = std::stoul(hex, 0, 16);
		b = std::stoul(hex, 0, 16);
		a = std::stoul(hex, 0, 16);
	}
	
	// Default Copy Constructor
	Color(const Color& col) = default;

	// Default Assignment Operator
	Color& operator= (const Color&) = default;
};
