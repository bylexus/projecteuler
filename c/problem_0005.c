#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Smallest multiple
 * Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */


int main(void)
{
    unsigned int nr = 20;
    // Only those divisors must be checked - all others are just factors of the others
    int nrOfDivs = 10;
    unsigned int divisors[nrOfDivs];
    divisors[0] = 20;
    divisors[1] = 19;
    divisors[2] = 18;
    divisors[3] = 17;
    divisors[4] = 16;
    divisors[5] = 15;
    divisors[6] = 14;
    divisors[7] = 13;
    divisors[8] = 12;
    divisors[9] = 11;
    bool found = false;

    while (true) {
        found = false;
        for (unsigned int i = 0; i < nrOfDivs; i++) {
            if (nr % divisors[i] > 0) {
                found = true;
                break;
            }
        }
        if (found) {
            nr++;
        } else {
            printf("Found smalles number that is divisible by all 1-20 numbers: %i\n", nr);
            break;
        }
    }
}
