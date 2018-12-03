#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Maximum path sum I
 * Problem 18
 *
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below (15x15 numbers):
 *
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67,
 * is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 *
 *
 * Idea:
 * --------
 * This is a directed graph problem. I calculate a new graph, containing the costs of each node (including biggest child costs):
 * I begin at the lowest level of the graph, calculating the cost of each node INCLUDING the cost of the more
 * costly child node. This leads to a graph containing the summed up cost on each node.
 *
 * In a 2nd step, I only have to travel down the graph to collect the most costly route.
 *
 * This is some sort of Dijkstra algorithm, for a directed graph.
 */

#define NRLENGTH 15
// #define NRLENGTH 4

int solution[NRLENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int numbers[NRLENGTH][NRLENGTH] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
    {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
/*
int solution[NRLENGTH] = {0, 0, 0, 0};
int numbers[NRLENGTH][NRLENGTH] = {
    {3, 0, 0, 0},
    {7, 4, 0, 0},
    {2, 4, 6, 0},
    {8, 5, 9, 3}};
*/

int costs[NRLENGTH][NRLENGTH];

int calculateNodeCost(row, col)
{
    // Out-of-bounds check:
    if (row >= NRLENGTH)
    {
        return 0;
    }
    int cost = numbers[row][col];
    int leftSubCost = calculateNodeCost(row + 1, col);
    int rightSubCost = calculateNodeCost(row + 1, col + 1);
    if (leftSubCost >= rightSubCost)
    {
        cost += leftSubCost;
    }
    else if (rightSubCost > 0)
    {
        cost += rightSubCost;
    }
    costs[row][col] = cost;
    return cost;
}

void findSolution(row, col)
{
    // Out-of-bounds check:
    if (row >= NRLENGTH)
    {
        return;
    }
    solution[row] = numbers[row][col];
    if (row + 1 >= NRLENGTH) {
        return;
    }
    if (costs[row + 1][col] >= costs[row + 1][col + 1])
    {
        findSolution(row + 1, col);
    }
    else
    {
        findSolution(row + 1, col + 1);
    }
}

int main(void)
{
    calculateNodeCost(0, 0);
    findSolution(0, 0);

    printf("Solution path: ");
    int checksum = 0;
    for (int i = 0; i < NRLENGTH; i++)
    {
        checksum += solution[i];
        printf("%d, ", solution[i]);
    }
    printf("\nChecksum: %d\n",checksum);
}
