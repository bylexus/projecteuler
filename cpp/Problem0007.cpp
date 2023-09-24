#ifndef EULER_PROBLEM_0007
#define EULER_PROBLEM_0007

#include <iostream>
#include "BaseProblem.h"
#include "lib/math.h"

using namespace euler;

/**
 * @see https://projecteuler.net:
 *
 * 10001st prime
 * Problem 7
 *
 * By listing the first six prime numbers:
 * 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10'001st prime number?
 */
class Problem0007 : public BaseProblem
{
    protected:
        long maxCount = 10001;

        virtual string getTitle() override {
            return "Problem 7 - 10'001st prime";
        }


        long i = 2;
        virtual void run(long &solution) override
        {
            while (maxCount > 0) {
                if (isPrime(i)) {
                    maxCount--;
                }
                i++;
            }
            solution = i - 1;
        }
};
#endif
