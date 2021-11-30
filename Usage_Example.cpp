#include <stdio.h>
#include <unistd.h>
#include "SnekGame.hpp"

int main()
{
	char key = 'X';
	SnekGame3D<> game(12,12,12);
	
	while (true)
	{
		//key = getKeyPress();
		if (game.nextFrame(key))
		{
			// display game.snek points as white
			// and game.food point as red color
			puts("running..");
		}
		else
		{
			// game over
			puts("\n\e[38;2mgame over!");
		}
		usleep(10000);
	}
}
