#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Power digit sum
 * Problem 16
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */



int double_nr(int *list, int list_length)
{
    int remainder = 0;
    int list_pos = 0;

    do {
        list[list_pos] = list[list_pos]*2 + remainder;
        remainder = list[list_pos] / 10;
        list[list_pos] = list[list_pos] % 10;
        list_pos++;
        if ( remainder > 0 && list[list_pos] == -1 ) {
            list[list_pos] = remainder;
            remainder = 0;
            break;
        }
    } while (list[list_pos] != -1);
    return list_pos;
}

int sum_nr(int *list, int end)
{
    int sum = 0;
    while (end >= 0 )
    {
        if (list[end] > -1) {
            sum += list[end];
        }
        end--;
    }
    return sum;
}

#define POW 1000

int main(void)
{
    int list_length = POW;
    int list[list_length];
    int list_pos = 0;

    // Initialize list with -1 (means: no number):
    for (int i = 0; i < list_length; i++) {
        list[i] = -1;
    }
    // set first list entry:
    list[0] = 2;

    for (int i = 2; i <= POW; i++)
    {
        list_pos = double_nr(list, list_length);
    }
    printf("Sum of digits of 2^1000: %d", sum_nr(list, list_pos));
}
