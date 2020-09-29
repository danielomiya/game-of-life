#pragma once

/**
 * Struct to define a generation of cells
 */
typedef struct generation
{
    int height, width; // (y, x)
    int **cells;
} Generation;

/**
 * Initializes a new generation (pseudo constructor)
 *
 * @param generation pointer to new generation
 * @param height amount of rows
 * @param width amount of columns
 */
void init_generation(Generation *generation, int height, int width);

/**
 * Prints a generation to stdout (using printf)
 *
 * @param generation pointer to generation
 */
void print_generation(Generation *generation);

/**
 * Produces a new generation based on given one
 *
 * @param generation pointer to generation
 * @return next generation
 */
Generation *make_next_generation(Generation *generation);

/**
 * Releases the memory allocated by malloc and calloc
 *
 * @param generation pointer to generation
 */
void free_generation(Generation *generation);
