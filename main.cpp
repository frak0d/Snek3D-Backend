
#include "SnekGame.hpp"

int main()
{
	char key = '0';
	SnekGame3D<> game(12,12,12);
	
	while (true)
	{
		//key = getKeyPress();
		if (game.nextFrame(key))
		{
			// display game.snek points as white
			// and game.food point as red color
		}
		else
		{
			// game over
		}
	}
}