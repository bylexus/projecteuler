#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Summation of primes
 * Problem 10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 * Note to self:
 * This is the Sieve of Erathostenes version, using an array with only odd numbers:
 *
 * int[] sieve = [3,5,7,9,11,...]
 *
 * The index of a number indicates its value: 2*i + 3 = value ==> i = (value - 3) / 2
 */

int main(void)
{
    unsigned long sum = 2;
    int border = 2000000;

    int * sieve = malloc(sizeof(int) * (border/2-1));
    // Fill the sieve:
    for (int i = 0; i < border/2-1; i++) {
        sieve[i] = 2*i+3;
    }

    // walk through the sieve, strike out multiplies of primes:
    int pos = 0;
    int walker = 0;
    int value = sieve[0];
    while (pos < border/2-1) {
        value = sieve[pos];
        walker = pos + value;
        // strike out all multiplies of the actual value:
        while (walker < border/2-1) {
            sieve[walker] = -1;
            walker += value;
        }

        // move to the next not-marked value:
        pos++;
        while(sieve[pos] == -1) {
            pos++;
        }
    }

    for (int i = 0; i < border/2-1; i++) {
        if (sieve[i] > -1) {
            sum += sieve[i];
        }
    }
    printf("The sum of all primes below 2'000'000 is %lu\n", sum);

}
