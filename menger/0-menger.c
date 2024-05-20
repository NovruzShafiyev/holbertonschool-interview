#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: No return
 */

void menger(int level)
{
	int size, width;
	int i = 0, j = 0;


	size = pow(3, level);

	if (level == 0)
		printf("#\n");
	else
	{
		while (i < size)
		{
			while (j < size)
			{
				width = size / 3;
				while (width >= 1)
				{
					if (((i / width) % 3 == 1 && (j / width) % 3 == 1))
					{
						printf(" ");
						break;
					}
					else if (i % 3 == 1 && j % 3 == 1)
					{
						printf(" ");
						break;
					}
					width /= 3;
				}
				if (width == 0)
					printf("#");
				j++;
			}
			printf("\n");
			i++;
			j = 0;
		}
	}
}
