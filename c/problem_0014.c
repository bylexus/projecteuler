#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Large sum
 * Problem 13
 *
 * Longest Collatz sequence
 * Problem 14
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms.
 * Although it has not been proved yet (Collatz Problem),
 * it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * --------------------------------------------------------------------------
 * Idea: Instead of just brute-forcing this, I try the following apporach:
 *
 * - For each number, I store the Collatz chain length, starting at 1, in an appropriate data structure.
 * - To calculate a sequence length of a number, I check if I have the NEXT number already in my datastructure.
 *   - If this is the case, it's just the calculated sequence length + 1.
 *   - If not, I calculate the chain length RECURSIVELY for the next number.
 *
 * Data structure:
 * I need a structure that can look up the chain length of a random number, but I don't know how many
 * random number can appear: These may well extend 1'000'000 by far (e.g. 999'999 already evaluates to 2'999'998 as next Collatz number)
 * So a Hash Map would be a good data strucure, which I will implement from scratch.
 *
 * Example:
 *               Nr:  0  1  2  3  4  5 ...
 * int chainLength = [0, 1, 2, 8, 3, 6, ...]
 *
 * Performance Notes:
 * -------------------
 *
 * After some experiencing, it all depends on the lookup speed of the hash map:
 * The more collissions the hash map must store, the slower it gets.
 * With a bucket size of 1'000'000, this tool runs in about 500ms.
 */

unsigned int nextCollatzNr(unsigned long nr)
{
    if (nr % 2 == 0)
    {
        return nr / 2;
    }
    else
    {
        return 3 * nr + 1;
    }
}

int collatzChainLength(ul_hashmap *map, unsigned long nr)
{
    // 1: done. Chain length is 1 for start nr 1.
    if (nr == 1) {
        return 1;
    }

    // Test if given nr has an already known chain length:
    ul_hashmap_node *node = ul_hashmap_get(map, nr);
    if (node) {
        return node->value;
    }


    // recursively calculate the chain length from the next nr:
    int length = collatzChainLength(map, nextCollatzNr(nr)) + 1;
    ul_hashmap_set(map, nr, length);
    return length;
}

#define MAXNR 1000000

int main(void)
{
    int startNr = 0;
    int longestChain = 0;

    ul_hashmap *map = ul_hashmap_create();

    for (int i = 1; i < MAXNR; i++)
    {
        int len = collatzChainLength(map, i);
        if (len > longestChain) {
            longestChain = len;
            startNr = i;
        }
    }
    printf("Longest chain found for %i: len %i\n",startNr, longestChain);
    // optional, because program ends (could save some miliseconds):
    // ul_hashmap_free(map);
}
