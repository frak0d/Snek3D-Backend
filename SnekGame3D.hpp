#pragma once

#include <deque>
#include <concepts>
#include <stdexcept>
#include <algorithm>

#include "Rand.hpp"
#include "Color.hpp"
#include "Point3D.hpp"

template <std::integral mint=uint16_t>
class SnekGame3D
{
private:
	Point3D<int8_t> last_move = {0,0,0};
	
public :
	uint16_t score = 0;
	Point3D<mint> food; // location of food
	Point3D<mint> wrld; // size of the world
	std::deque<Point3D<mint>> snek; //pieces of snek
	
	bool nextFrame(char movement='0')
	{
		using p3d = Point3D<mint>;
		
		Point3D<int8_t> move;
		/*
		 * Movements :-
		 * x : -x axis
		 * y : -y axis
		 * z : -z axis
		 * X : +x axis
		 * Y : +y axis
		 * Z : +z axis
		 */
		switch (movement)
		{
		case 'x':
			move = {-1,0,0};
			break;
		case 'y':
			move = {0,-1,0};
			break;
		case 'z':
			move = {0,0,-1};
			break;
		case 'X':
			move = {+1,0,0};
			break;
		case 'Y':
			move = {0,+1,0};
			break;
		case 'Z':
			move = {0,0,+1};
			break;
		default :
			move = last_move;
			break;
		}
		
		last_move = move;
		snek.push_front(snek[0] + move);
		snek.pop_back();
		
		// If Food is eaten
		if (snek[0] == food)
		{
			score += 1;
			food = rand_coord({1,1,1}, wrld, {255, 50, 50});
		}
		
		// Check Self Collision
		else if (std::find(snek.begin()+1, snek.end(), snek[0]) != snek.end())
		{
			return false; // Game Over
		}
		
		// Check Boundary Collision
		else if (snek[0] < p3d{1,1,1} || snek[0] > wrld)
		{
			return false; // Game Over
		}
		
		return true; // game not over
	}
	
	SnekGame3D(mint x_sz=16, mint y_sz=16, mint z_sz=16)
	{
		if (x_sz < 4 || y_sz < 4 || z_sz < 4)
			throw std::runtime_error("World Size too Small, Need Atleast 4x4x4 World !");
		else
			wrld = {x_sz, y_sz, z_sz};
		
		food = rand_coord({1,1,1}, wrld, {255, 50, 50}); // initial food (red)
		snek.push_back(rand_coord({1,1,1}, wrld, {255,255,255})); // initial snek (white)
	}
};
