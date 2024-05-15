#include "slide_line.h"

/**
 * Slide and merge an array of integers to the left or right.
 *
 * @param line      Pointer to an array of integers.
 * @param size      Number of elements in the array.
 * @param direction Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * @return 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    int i, j;

    if (line == NULL || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT))
        return 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 1, j = 0; i < (int)size; i++)
        {
            if (line[i] != 0)
            {
                if (line[i] == line[j])
                {
                    line[j++] *= 2;
                    line[i] = 0;
                }
                else if (line[j] == 0)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                else
                {
                    j++;
                    if (i != j)
                    {
                        line[j] = line[i];
                        line[i] = 0;
                    }
                }
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 2, j = size - 1; i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (line[i] == line[j])
                {
                    line[j--] *= 2;
                    line[i] = 0;
                }
                else if (line[j] == 0)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                else
                {
                    j--;
                    if (i != j)
                    {
                        line[j] = line[i];
                        line[i] = 0;
                    }
                }
            }
        }
    }

    return 1;
}
