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

	const int socket = OpenFlaschenTaschenSocket(hostname);
	UDPFlaschenTaschen canvas(socket, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	int x, y;
	for (x = 0; x < DISPLAY_WIDTH; x++)
	{
		for (y =0; y < DISPLAY_HEIGHT; y++)
		{
			canvas.SetPixel(x, y, Color(255,0,0));
		}
	}
}
