#pragma once

#include <map>
#include <deque>
#include <concepts>
#include <stdexcept>
#include <algorithm>
#include <utility>

#include "Rand.hpp"
#include "Color.hpp"
#include "Point3D.hpp"

template <std::integral mint>
struct Snek
{
	uint16_t score = 0;
	const Color color;
	std::deque<Point3D<mint>> parts;
	Point3D<int8_t> last_move = {0,0,0};

	Snek(Color color) : color{color} {}
};

template <std::integral mint=uint16_t>
class MultiSnekGame3D
{
private:
	std::map<uint64_t, Snek<mint>> players;

public:
	Point3D<mint> food; // location of food
	Point3D<mint> wrld; // size of the world

	void addPlayer(uint64_t playerid, Color color)
	{
		auto [elem,done] = players.insert({playerid, Snek<mint>{color}});
		elem->second.parts.push_back(rand_coord({1,1,1}, wrld, color)); // initial snek
	}

	void delPlayer(uint64_t playerid)
	{
		players.erase(playerid);
	}

	uint16_t getScore(uint64_t playerid)
	{
		return players.at(playerid).score;
	}

	const auto& getSnek(uint64_t playerid)
	{
		return players.at(playerid);
	}

	bool nextFrame(uint64_t playerid, char movement='0')
	{
		using p3d  = Point3D<mint>;
		auto& snek = players.at(playerid);
		
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
		default:
			move = {0,0,0};
			break;
		}
		
		snek.parts.push_front(snek.parts[0] + move);
		snek.parts.pop_back();
		
		// If Food is eaten
		if (snek.parts[0] == food)
		{
			snek.score += 1;
			food = rand_coord({1,1,1}, wrld, {255, 50, 50});
		}

		// Check Boundary Collision
		else if (snek.parts[0] < p3d{1,1,1} || snek.parts[0] > wrld)
		{
			return false; // Game Over
		}

		// Check Snek Collisions
		else for (const auto& [id,snek2] : players)
		{
			if (std::find(snek2.parts.begin(), snek2.parts.end(), snek.parts[0]) != snek2.parts.end())
			{
				return false; // Game Over
			}
		}
		
		return true; // game not over
	}
	
	MultiSnekGame3D(mint x_sz=16, mint y_sz=16, mint z_sz=16)
	{
		if (x_sz < 4 || y_sz < 4 || z_sz < 4)
			throw std::runtime_error("World Size too Small, Need Atleast 4x4x4 World !");
		else
			wrld = {x_sz, y_sz, z_sz};
		
		food = rand_coord({1,1,1}, wrld, {255, 50, 50}); // initial food (red)
	}
};
