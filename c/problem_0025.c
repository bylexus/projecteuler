#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * 1000-digit Fibonacci number
 * Problem 25
 *
 * The Fibonacci sequence is defined by the recurrence relation:
 *
 *     Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 *
 * Hence the first 12 terms will be:
 *
 *     F1 = 1
 *     F2 = 1
 *     F3 = 2
 *     F4 = 3
 *     F5 = 5
 *     F6 = 8
 *     F7 = 13
 *     F8 = 21
 *     F9 = 34
 *     F10 = 55
 *     F11 = 89
 *     F12 = 144
 *
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

int main(void)
{
    bignum_int *results[3];
    int number_index = 2;
    results[0] = bignum_int_create(1000, 1);
    results[1] = bignum_int_create(1000, 1);
    // results[2] = bignum_int_sum(results[0], results[1], 1000);

    while (results[(number_index - 1) % 3]->length < 1000)
    {
        bignum_int *tmp = bignum_int_sum(
            results[(number_index - 1) % 3],
            results[(number_index - 2) % 3], 1000);
        results[number_index % 3] = tmp;
        number_index++;
    }
    printf("First Fibonacci Number with 1000 digits: #%d: %s\n", number_index, bignum_int_str(results[(number_index - 1) % 3]));
}
