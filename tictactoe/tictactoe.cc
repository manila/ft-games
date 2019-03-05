#include "udp-flaschen-taschen.h"

#include <vector>
#include <unistd.h>
#include <stdio.h>

#define DISPLAY_WIDTH 45
#define DISPLAY_HEIGHT 35

#define GRID_SQUARE_SIZE 11
#define GRID_LINE_WIDTH 1

#define Z_LAYER 7

void draw_grid(void)
{
	
}

void draw_game(char **fb, int width, int height)
{
	int x, y;
	for (x = 0; x < width; i++)
	{
		for (y =0; y < width; y++)
		{
			canvas.SetPixel(x, y, fb[x][y]);
		}
	}
}

void game_loop(UDPFlaschenTaschen *canvas)
{

}

int main(int ac, char *av[])
{
	const char *hostname = NULL;
	if (av > 1)
	{
		hostname = av[1];
	}

	const int socket = OpenFlaschenTaschenSocket(hostname);
	UDPFlaschenTaschen canvas(socket, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	const Color bg(255, 255, 255);
}

