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
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 *
 * Description: A sandpile is considered stable when none of its cells contains more than 3 grains.
 * When this function is done, grid1 must be stable.
 * grid1 must be printed before each toppling round, only if it is unstable.
 * You’re not allowed to allocate memory dynamically.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable;

    do {
        unstable = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                grid1[i][j] += grid2[i][j];
            }
        }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    unstable = 1;
                    printf("=\n");
                    print_grid(grid1);
                    toppling(grid1);
                    break;
                }
            }
            if (unstable)
                break;
        }
    } while (unstable);
}

/**
 * toppling - Perform toppling operation on the grid
 * @grid: 3x3 grid
 *
 */
static void toppling(int grid[3][3])
{
    int i, j, temp_grid[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            temp_grid[i][j] = grid[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (temp_grid[i][j] > 3) {
                grid[i][j] -= 4;
                if (i > 0)
                    grid[i - 1][j]++;
                if (i < 2)
                    grid[i + 1][j]++;
                if (j > 0)
                    grid[i][j - 1]++;
                if (j < 2)
                    grid[i][j + 1]++;
            }
        }
    }
}
