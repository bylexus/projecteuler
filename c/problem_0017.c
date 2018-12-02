#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Number letter counts
 * Problem 17
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
 * The use of "and" when writing out numbers is in compliance with British usage.
 */

int main(void)
{
    int single[] = {
        0, // zero, never said
        3, // one
        3, // two
        5, // three
        4, // four
        4, // five
        3, // six
        5, // seven
        5, // eight
        4, // nine
        3, // ten
        6, // eleven
        6, // twelve
        8, // thirteen
        8, // fourteen
        7, // fifteen
        7, // sixteen
        9, // seventeen
        8, // eighteen
        8  // nineteen
    };

    int tenths[] = {
        0, // not counted
        3, // ten, but should not be used
        6, // twenty
        6, // thirty
        5, // forty
        5, // fifty
        5, // sixty
        7, // seventy
        6, // eighty
        6  // ninety
    };

    int hundred = 7; // "hundred"
    int counter = 0, i;

    for (int h = 0; h < 10; h++)
    {
        // h is the hundred counter
        if (h > 0)
        {
            // count e.g. "one hundred"
            counter += single[h] + hundred;
        }

        // count up to (but not including) twenty, as those are special:
        for (i = 1; i < 20; i++)
        {
            if (h > 0)
            {
                // count e.g. "one hundred"
                counter += single[h] + hundred;
                counter += 3; // the "and" from "one hundred and xxx"
            }
            // count e.g. 'twelve"
            counter += single[i];
        }

        for (i = 20; i < 100; i++)
        {
            if (h > 0)
            {
                // count e.g. "one hundred"
                counter += single[h] + hundred;
                counter += 3; // the "and" from "one hundred and xxx"
            }
            // count from 20 to 99:
            counter += tenths[i / 10]; // tenth, e.g. "twenty"
            counter += single[i % 10]; // e.g. "one"
        }
    }

    counter += 11; // "one thousand"

    printf("All words from 1 to 1000 have %d letters.\n", counter);
}
