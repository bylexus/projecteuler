#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Counting Sundays
 * Problem 19
 *
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 *     1 Jan 1900 was a Monday.
 *     Thirty days has September,
 *     April, June and November.
 *     All the rest have thirty-one,
 *     Saving February alone,
 *     Which has twenty-eight, rain or shine.
 *     And on leap years, twenty-nine.
 *     A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

int isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main(void)
{
    int sundayCounter = 0;
    int year = 1900;
    int month = 1; // months go from 1 to 12
    int dom = 1; // day of month
    int weekday = 0; // 0 = Monday, 6 = Sunday

    while (!( year == 2000 && month == 12 && dom == 31 )) {
        // check for sunday to count:
        if (year > 1900 && dom == 1 && weekday == 6 ) {
            sundayCounter++;
        }

        // increase things:
        weekday = (weekday + 1) % 7;
        dom++;

        // February? Then check month overflow:
        if (dom == 29) {
            if (!isLeapYear(year) && month == 2) {
                dom = 1;
                month += 1;
            }
        }
        if (dom == 30) {
            if (isLeapYear(year) && month == 2) {
                dom = 1;
                month += 1;
            }
        }
        if (dom == 31) {
            if (month == 4 || month == 6 || month == 9 || month == 11 ) {
                dom = 1;
                month += 1;
            }
        }

        if (dom == 32) {
            dom = 1;
            month += 1;
        }

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    printf("Number of sundays on 1st of Month within the 20th century: %d\n", sundayCounter);
}
