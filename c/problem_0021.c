#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Amicable numbers
 * Problem 21
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
 * The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 */

/**
 * sum of (single) divisors)
 */
int divsum(int n)
{
    int sum = 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main(void)
{
    int divsum1;
    int divsum2;
    int sum = 0;
    for (int i = 2; i < 10000; i++)
    {
        divsum1 = divsum(i);
        divsum2 = divsum(divsum1);
        if (i == divsum2 && i < divsum1)
        {
            printf("%d/%d\n", i, divsum1);
            sum = sum + i + divsum1;
        }
    }
    printf("Sum of all amicable numbers below 10000: %d\n", sum);
}
