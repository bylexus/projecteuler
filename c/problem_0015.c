#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Lattice paths
 * Problem 15
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

unsigned long calcRoutes(int size, int startX, int startY)
{
    unsigned long sum = 0;
    if (startX == size-1 && startY == size-1) {
        return 1;
    }
    // Can I go right?
    if (startX < size - 1) {
        sum += calcRoutes(size, startX+1, startY);
    }
    // Can I go down?
    if (startY < size - 1) {
        sum += calcRoutes(size, startX, startY+1);
    }
    return sum;
}

#define MAP_SIZE 21
int main(void)
{
    unsigned long nrOfRoutes = calcRoutes(MAP_SIZE, 0, 0);
    printf("Nr of routes in a %ix%i grid: %lu\n", MAP_SIZE - 1, MAP_SIZE - 1, nrOfRoutes);
}
