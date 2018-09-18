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
 */

int main(void)
{
    unsigned long sum = 2;
    unsigned long prime = 3;

    while (prime < 2000000) {
        sum += prime;
        prime += 2;
        while (!isPrime(prime)) {
            prime += 2;
        }
    }

    printf("The sum of all primes below 2'000'000 is %lu\n", sum);
}
