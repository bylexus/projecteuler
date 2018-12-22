#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Factorial digit sum
 * Problem 20
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

int main(void)
{
    char digits[200];
    int charPointer = 0;
    digits[0] = 1;
    int n = 100;
    int rest = 0;
    int tmp = 0;

    // calc
    for (int i = 2; i <= n; i++)
    {
        for (int digit = 0; digit <= charPointer; digit++)
        {
            tmp = digits[digit] * i + rest;
            digits[digit]  = tmp % 10;
            rest = tmp / 10;
        }
        while (rest > 0)
        {
            charPointer++;
            digits[charPointer] = rest % 10;
            rest = rest / 10;
        }
    }

    // sum + Output:
    int sum = 0;
    for (int i = charPointer; i >= 0; i--) {
        sum += digits[i];
        printf("%d",digits[i]);
    }
    printf("\nSum of digits: %d\n",sum);
}
