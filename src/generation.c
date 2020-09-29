#include <stdlib.h>
#include <stdio.h>
#include "generation.h"

void init_generation(Generation *generation, int height, int width)
{
    int i;
    generation->height = height;
    generation->width = width;

    generation->cells = (int **)malloc(sizeof(int *) * height);

    for (i = 0; i < height; i++)
    {
        generation->cells[i] = (int *)calloc(width, sizeof(int));
    }
}

void print_generation(Generation *generation)
{
    int i, j;

    printf("\n");

    for (i = 0; i < generation->height; i++)
    {
        for (j = 0; j < generation->width; j++)
        {
            printf(" %d ", generation->cells[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(Generation *generation, int row, int col)
{
    int count = 0, i, j, pos_i, pos_j;

    for (i = -1; i < 2; i++)
    { // relative positions
        pos_i = row + i;

        if ((pos_i < 0) || (pos_i >= generation->height))
            continue; // first or last row

        for (j = -1; j < 2; j++)
        {
            pos_j = col + j;

            if ((pos_j < 0) || (pos_j >= generation->width))
                continue; // first or last column

            count += generation->cells[pos_i][pos_j];
        }
    }

    count -= generation->cells[row][col]; // remove the cell itself from count
    return count;
}

Generation *make_next_generation(Generation *prev_generation)
{
    int i, j, n;
    Generation *generation = malloc(sizeof(Generation));
    init_generation(generation, prev_generation->height, prev_generation->width);

    for (i = 0; i < generation->height; i++)
    {
        for (j = 0; j < generation->width; j++)
        {
            n = count_neighbors(prev_generation, i, j);

            if (prev_generation->cells[i][j] == 0)
                generation->cells[i][j] = (n == 3) ? 1 : 0;
            else
                generation->cells[i][j] = ((n < 2) || (n > 3))
                                              ? 0
                                              : prev_generation->cells[i][j];
        }
    }

    return generation;
}

void free_generation(Generation *generation)
{
    int i;

    for (i = 0; i < generation->height; i++)
    {
        free(generation->cells[i]);
    }

    free(generation->cells);
    free(generation);
}
