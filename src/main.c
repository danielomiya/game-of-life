#include <stdlib.h>
#include <stdio.h>

#if !defined(_WIN32) && !defined(_WIN64)
#define UNIX_FLAG 1
#include <unistd.h>
#endif

#include "generation.h"

#define DEBUG 0

void input_generation(Generation *generation);
void output_generation(Generation *generation);

int main(int argc, char **argv)
{
    int height, width;
    Generation *generation = malloc(sizeof(Generation)), *tmp;

#if DEBUG
    height = 3, width = 3;
#else
    printf("Enter number of rows: ");
    scanf("%d", &height);

    printf("Enter number of columns: ");
    scanf("%d", &width);
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

        output_generation(generation);
    } while (1);


}

void input_generation(Generation *generation)
{
    int i, j, rows, columns;
    int cont = 0;
    int a;
    FILE *file;

    rows = generation->height;
    columns = generation->width;

    if ((file = fopen("data/input.txt", "r")) != NULL){
        for (i = 0; i < rows; i++){
            for (j = 0; j < columns; j++){ 
                fscanf(file, "%i", &a);
                generation->cells[i][j] = a;
            }
        }
    }
}

void output_generation(Generation *generation){
  int i, j, rows, columns;
    int cont = 0;
    FILE *file;

    rows = generation->height;
    columns = generation->width;

    if ((file = fopen("data/output.txt", "a")) != NULL){
        for (i = 0; i < rows; i++){
          for (j = 0; j < columns; j++){ 
            fprintf(file, "%i ", generation->cells[i][j]);
          }
          fprintf(file, "\n");
        }
      fprintf(file, "\n");
      fclose(file);
    }
}
