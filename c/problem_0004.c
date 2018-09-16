#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

bool isPalindrome(unsigned long nr)
{
    unsigned long p = 0;
    unsigned long n = nr;
    while (n > 0) {
        p = 10*p + n % 10;
        n = n / 10;
    }
    return nr == p;
}

int main(void)
{
    unsigned int maxPalindrome = 0;
    unsigned int maxI, maxJ = 0;

    /**
     * Idea:
     * 1. build products of 3-digit numbers from 100 to 999, beginning at the top.
     * 2. Check if the product is a palindrome.
     * 3. Check if we found one that was bigger before. remember max value.
     */

    for (unsigned int i = 999; i >= 100; i--)
    {
        for (unsigned int j = i; j >= 100; j--)
        {
            if (isPalindrome(i * j))
            {
                if (maxPalindrome < i * j) {
                    maxPalindrome = i * j;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }
    printf("Palindrome found: %u, product of %u * %u\n", maxPalindrome, maxI, maxJ);
}
