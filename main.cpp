#include <csignal> 
#include <stdio.h>
#include <unistd.h>
#include "SnekGame.hpp"

void InterruptHandler(int signum)
{
	puts("\n\e[33;2m >> Interrupt Recieved, Exiting... \e[0m");
	exit(signum);
}

int main()
{
	std::signal(SIGINT, InterruptHandler);
	char key = 'X';
	SnekGame3D<> game(12,12,12);
	
	while (true)
	{
		//key = getKeyPress();
		if (game.nextFrame(key))
		{
			// display game.snek points as white
			// and game.food point as red color
			printf("running.. %d %d %d\n",
			game.snek[0].x, game.snek[0].y, game.snek[0].z);
		}
		else
		{
			// game over
			puts("\n\e[38;2mgame over!");
		}
		usleep(500000);
	}
}
