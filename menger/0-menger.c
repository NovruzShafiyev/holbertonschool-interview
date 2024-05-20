#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_menger_hole - Checks if the given position (x, y) is part of the hole.
 * @x: The x coordinate.
 * @y: The y coordinate.
 *
 * Return: 1 if it is a hole, otherwise 0.
 */
int is_menger_hole(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return (1);
        x /= 3;
        y /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 *
 * Return: void
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (is_menger_hole(x, y))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
