#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Non-abundant sums
 * Problem 23
 *
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that
 * cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 *
 * Idea
 * -----
 * - Create a list with all abundant numbers from 12 - 28123. Create a hashmap of the numbers,
 *   for faster check access in the next step
 * - Check all numbers from 1 - (including) 28123 if they can be written as the sum of 2 numbers from the abundant list
 */

/**
 * Checks if the given int is an abundant number (sum of its proper divisors > n)
 */
char isAbundant(unsigned int n)
{
    if (divsum(n) > n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    // ordered list of abundant numbers
    int abundant_numbers[28123];
    int arr_length = 0;

    // Step 1: Create abundant map:
    for (unsigned int i = 12; i < 28123; i++)
    // for (unsigned int i = 12; i < 100; i++)
    {
        if (isAbundant(i))
        {
            abundant_numbers[arr_length++] = i;
        }
    }

    // Step 2: check all numbers from 1 - 28123 if they can be
    // built of the sum of 2 abundant numbers
    long sum = 0;
    char found = 0;
    for (int i = 1; i <= 28123; i++)
    {
        // loop over all abundant numbers as ai:
        // if i - ai is also an abundant number,
        // don't add i to the sum.
        // Only if no abundant pair can be found, add i to the sum.
        found = 0;
        for (int ai = 0; ai < arr_length; ai++)
        {
            if (binsearch(i - abundant_numbers[ai], abundant_numbers, 0, arr_length) > -1)
            {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            sum += i;
        }
    }

    printf("Sum of integers that cannot be formed of the sum of 2 abundant numbers: %ld\n", sum);

    // for (int i = 0; i < arr_length; i++)
    // {
    //     printf("%d\n", abundant_numbers[i]);
    // }
}
