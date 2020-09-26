#pragma once

typedef struct generation {
    int height, width; // (y, x)
    int** cells;
} Generation;

void init_generation(Generation *generation, int height, int width);
void print_generation(Generation *generation);
Generation* make_next_generation(Generation *generation);
void free_generation(Generation *generation);
