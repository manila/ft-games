#include "udp-flaschen-taschen.h"

#include <vector>
#include <unistd.h>
#include <stdio.h>

#define DISPLAY_WIDTH 45
#define DISPLAY_HEIGHT 35

#define GRID_SQUARE_SIZE 11
#define GRID_LINE_WIDTH 1

#define Z_LAYER 7

int main(int ac, char *av[])
{
	const char *hostname = NULL;
	if (ac > 1)
	{
		hostname = av[1];
	}
	else
	{
		hostname = "ft.noise";
	}

	const int socket = OpenFlaschenTaschenSocket(hostname);
	UDPFlaschenTaschen canvas(socket, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	int x, y;
	int ball_x, ball_y, ball_dir_x, ball_dir_y;
	
	
	ball_x = 0;
	ball_y = 0;
	ball_dir_x = 1;
	ball_dir_y = 1;

	while (1)
	{
		for (x = 0; x < DISPLAY_WIDTH; x++)
		{
			for (y = 0; y < DISPLAY_HEIGHT; y++)
			{
				canvas.SetPixel(x, y, Color(1,0,0));
			}
		}
		
		canvas.SetPixel(ball_x+=ball_dir_x, ball_y+=ball_dir_y, Color(255,0,0));

		canvas.SetOffset(0,0,5);

		if (ball_x == DISPLAY_WIDTH)
		{
			ball_dir_x = -1;
		}

		if (ball_y == DISPLAY_HEIGHT)
		{
			ball_dir_y = -1;
		}

		if (ball_y < 1)
		{
			ball_dir_y = 1;
		}

		if (ball_x < 1)
		{
			ball_dir_x = 1;
		}

		canvas.Send();

		usleep(1000/16);
	}
}
