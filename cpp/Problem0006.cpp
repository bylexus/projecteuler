#ifndef EULER_PROBLEM_0006
#define EULER_PROBLEM_0006

#include <iostream>
#include <cmath>
#include "BaseProblem.h"

/**
 * @see https://projecteuler.net:
 *
 * Sum square difference
 * Problem 6
 *
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers
 * and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the
 * first one hundred natural numbers and the square of the sum.
 */
class Problem0006 : public BaseProblem
{
    protected:
        long maxNr = 100;

        virtual string getTitle() override {
            return "Problem 6 - Sum square difference";
        }


        virtual void run(long &solution) override
        {
            long squareOfSum = pow((maxNr*maxNr + maxNr) / 2,2);
            long sumOfSquares = 0;
            for (int i = 1; i <= maxNr; ++i)
            {
                sumOfSquares += (i*i);
            }
            solution = squareOfSum - sumOfSquares;
        }
};
#endif
