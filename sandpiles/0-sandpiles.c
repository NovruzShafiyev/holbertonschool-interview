#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Description: Computes the sum of two sandpiles. Modifies grid1 to be stable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;
    int temp_grid[3][3];

    while (!stable)
    {
        stable = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp_grid[i][j] = grid1[i][j] + grid2[i][j];
                if (temp_grid[i][j] > 3)
                    stable = 0;
            }
        }

        if (!stable)
        {
            printf("=\n");
            print_grid(temp_grid);

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    grid1[i][j] = temp_grid[i][j] - 4;
                    if (grid1[i][j] < 0)
                        grid1[i][j] = 0;
                }
            }
        }
    }
}
