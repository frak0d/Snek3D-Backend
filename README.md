# Snek3D-Backend
This repo contains the backend for Snek3D game, originally made to be played on a 3d LED Cube.

## Usage (pseudocode) :-
```cpp
#include "SnekGame.hpp"

int main()
{
	SnekGame3D<> game(12,10,16); // for a 12x10x16 cuboid world
	
	while (true)
	{
		char key = getControllerKeyPress();
		if (game.nextFrame(key))
		{
			// display points in game.snek deque as white
			// and game.food point as red color (like 🍎)
			
			// length_of_snake = game.snek.length()
			// current_score = game.score
			
			// game.snek is a deque of Point3D objects (has x,y,z variables)
			// so snake head position = game.snek[0]
			// x coordinate of snake head = game.snek[0].x
		}
		else
		{
			// game over
		}
		
		// sleep(0.5 seconds) to reduce snake speed
		// otherwise it's too fast to be playable
	}
}
```
