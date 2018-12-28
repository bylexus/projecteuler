#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Lexicographic permutations
 * Problem 24
 *
 * A permutation is an ordered arrangement of objects. For example,
 * 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically,
 * we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the
 * digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 *
 * Idea
 * --------
 *
 * I didn't investigate in the mathematical theory, so I give the brute force
 * method a try:
 * 1. Create all permutations (n digits = n! permutations, in this case around 3 Millions)
 * 2. Sort them using quicksort
 * 3. pick the 1'000'000th!
 *
 * It worked, in about 74 seconds. This is slow, maybe can be improved.
 * Another idea is to form a linked list, and insert the items in lexicographic order.
 * Or a ring linked list, to make travelling the list a bit faster.
 */

int nrOfPerms = 0;

void swap(char *str, int p1, int p2)
{
    char tmp = str[p1];
    str[p1] = str[p2];
    str[p2] = tmp;
}

void permute(char *str, char **permutations, int left, int right)
{
    if (left == right)
    {
        permutations[nrOfPerms] = malloc((strlen(str) + 1) * sizeof(char));
        strcpy(permutations[nrOfPerms], str);
        // printf("%s\n", permutations[nrOfPerms]);
        nrOfPerms++;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(str, left, i);
            permute(str, permutations, left + 1, right);
            swap(str, left, i);
        }
    }
}

int main(void)
{
    char **permutations;
    unsigned long arrsize = factorial(10);
    // unsigned long arrsize = factorial(4);
    permutations = malloc(arrsize * sizeof(char *));
    // char str[] = "0123";
    char str[] = "0123456789";

    permute(str, permutations, 0, strlen(str) - 1);
    // selectionSort(permutations, nrOfPerms);
    quickSort(permutations, 0, nrOfPerms - 1);

    // for (int i = 0; i < nrOfPerms; i++) {
    //     printf("%s\n", permutations[i]);
    // }

    printf("The 1'000'000th permutation of %s is: %s\n",str,permutations[1000000-1]);
}
