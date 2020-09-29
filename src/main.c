#include <stdlib.h>
#include <stdio.h>

#if !defined(_WIN32) && !defined(_WIN64)
#define UNIX_FLAG 1
#include <unistd.h>
#endif

#include "generation.h"

#define DEBUG 1

void input_generation(Generation *generation);

int main(int argc, char **argv)
{
    int height, width;
    Generation *generation = malloc(sizeof(Generation)), *tmp;

#if DEBUG
    height = 6, width = 5;
#else
    printf("Enter number of rows: ");
    scanf_s("%d", &height);

    printf("Enter number of columns: ");
    scanf_s("%d", &width);
#endif

    init_generation(generation, height, width);
    input_generation(generation);

    do
    {
        print_generation(generation);

#if UNIX_FLAG
        sleep(1);
#else
        printf("\nPress ENTER to continue or CTRL+C to exit");
        getchar();
#endif

        tmp = make_next_generation(generation);

        free_generation(generation);

        generation = tmp;
    } while (1);
}

void input_generation(Generation *generation)
{
    /// TODO: find better ways to input first generation
#if DEBUG

    generation->cells[0][0] = 0;
    generation->cells[0][1] = 0;
    generation->cells[0][2] = 0;
    generation->cells[0][3] = 0;
    generation->cells[0][4] = 0;

    generation->cells[1][0] = 0;
    generation->cells[1][1] = 0;
    generation->cells[1][2] = 1;
    generation->cells[1][3] = 0;
    generation->cells[1][4] = 0;

    generation->cells[2][0] = 0;
    generation->cells[2][1] = 0;
    generation->cells[2][2] = 1;
    generation->cells[2][3] = 0;
    generation->cells[2][4] = 0;

    generation->cells[3][0] = 0;
    generation->cells[3][1] = 0;
    generation->cells[3][2] = 1;
    generation->cells[3][3] = 0;
    generation->cells[3][4] = 0;

    generation->cells[4][0] = 0;
    generation->cells[4][1] = 0;
    generation->cells[4][2] = 1;
    generation->cells[4][3] = 0;
    generation->cells[4][4] = 0;

    generation->cells[5][0] = 0;
    generation->cells[5][1] = 0;
    generation->cells[5][2] = 0;
    generation->cells[5][3] = 0;
    generation->cells[5][4] = 0;

#else

    int i, j;

    for (i = 0; i < generation->height; i++)
    {
        for (j = 0; j < generation->width; j++)
        {
            printf("Enter value of m(%d, %d): ", i, j);
            scanf_s("%d", &generation->cells[i][j]);
        }
    }

#endif
}
