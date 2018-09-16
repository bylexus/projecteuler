#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Sum square difference
 * Problem 6
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

unsigned int squareOfSum(n) {
    unsigned int sum = n*(n+1)/2;
    return sum*sum;
}

unsigned int sumOfSquares(n) {
    unsigned int sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        sum += i*i;
    }
    return sum;
}

int main(void)
{
    unsigned int soq = sumOfSquares(100);
    unsigned int sqs = squareOfSum(100);
    printf("Diff sum((1-100)^2):%i - (sum(1-100))^2:%i => %i\n", sqs, soq, sqs - soq);
}
