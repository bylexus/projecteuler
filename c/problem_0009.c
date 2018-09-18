#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @see https://projecteuler.net:
 *
 * Special Pythagorean triplet
 * Problem 9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

int main(void)
{
    int i, j, k;

    for (i = 1000; i > 0; i--)
    {
        for (j = i - 1; j > 0; j--)
        {
            k = 1000 - i - j;
            {
                if (k > 0 && k * k + j * j == i * i)
                {
                    printf("Found Pythagorean triplet %i + %i + %i = 1000\n", k, j, i);
                    printf("The product of them is: %i\n", k * j * i);
                    exit(0);
                }
            }
        }
    }
    printf("Hmm... No Pythagorean Triplet found that sums to 0... Something went wrong!\n");
}
