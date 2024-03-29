#ifndef EULER_PROBLEM_0002_RECURSIVE
#define EULER_PROBLEM_0002_RECURSIVE

#include <iostream>
#include "BaseProblem.h"
/**
 * @see https://projecteuler.net:
 *
 * Even Fibonacci numbers
 * Problem 2
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms.
 * By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms.
 *
 * COMMENT:
 * This is the recursive variant, just to check if it is somewhat slower than the iterative variant.
 * This is NOT optimized: It could be optimized by increase the act counter by the power of two, and check if it
 * exeeds the maximum, then bisect for the correct solution.
 */
class Problem0002_recursive : public BaseProblem
{
    protected:
        long act{0};
        long sum{0};
        long counter{1};

        virtual string getTitle() override {
            return "Problem 2 - recursive variant";
        }

        virtual void init() override
        {
            act = 0;
            sum = 0;
            counter = 1;
        }

        long fibo(const long &nr)
        {
            if (nr == 0)
            {
                return 0;
            }
            if (nr == 1)
            {
                return 1;
            }
            return fibo(nr - 1) + fibo(nr - 2);
        }

        virtual void run(long &solution) override
        {
            while (act < 4000000)
            {
                if (act % 2 == 0)
                {
                    sum += act;
                }
                act = fibo(counter);
                counter++;
            }
            solution = sum;
        }
};

#endif
