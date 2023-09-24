#ifndef EULER_PROBLEM_0005
#define EULER_PROBLEM_0005

#include <iostream>
#include <vector>
#include "BaseProblem.h"

/**
 * @see https://projecteuler.net:
 *
 * Smallest multiple
 * Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
class Problem0005 : public BaseProblem
{
    protected:

        virtual string getTitle() override {
            return "Problem 5 - Smallest multiple";
        }


        virtual void run(long &solution) override
        {
            long nr{20};
            // Only those divisors must be checked - all others are just factors of the others
            std::vector<long> divisors = {20,19,18,17,16,15,14,13,12,11};
            bool found = false;

            while (true)
            {
                found = false;
                for (long div : divisors)
                {
                    if (nr % div > 0)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    nr += 2;
                }
                else
                {
                    solution = nr;
                    return;
                }
            }
        }
};
#endif
