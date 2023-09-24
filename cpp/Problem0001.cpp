#ifndef EULER_PROBLEM_0001
#define EULER_PROBLEM_0001

#include <iostream>
#include "BaseProblem.h"
/**
 * @see https://projecteuler.net:
 *
 * Multiples of 3 and 5
 * Problem 1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */
class Problem0001 : public BaseProblem
{
    protected:

        int sum{0};

        virtual string getTitle() override {
            return "Problem 1";
        }

        virtual void init() override
        {
            sum = 0;
        }

        virtual void run(long &solution) override
        {
            for (int i = 0; i < 1000; i++)
            {
                if (i % 3 == 0 || i % 5 == 0)
                {
                    sum += i;
                }
            }
            solution = sum;
        }
};

#endif
