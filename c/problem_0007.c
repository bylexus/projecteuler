#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * 10001st prime
 * Problem 7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */


int main(void)
{
    int found = 0;
    int stop = 10001;
    unsigned long test = 2;
    while (found < stop) {
        if (isPrime(test)) {
            found++;
        }
        test++;
    }

    printf("the #%i prime is: %lu\n", found, test-1);
}
