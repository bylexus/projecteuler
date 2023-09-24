#ifndef EULER_PROBLEM_0003
#define EULER_PROBLEM_0003

#include <iostream>
#include <deque>
#include "BaseProblem.h"
#include "lib/math.h"

/**
 * @see https://projecteuler.net:
 *
 * Largest prime factor
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */
class Problem0003 : public BaseProblem
{
    protected:
        std::deque<long> factors;
        long testNumber{600851475143L};

        virtual string getTitle() override {
            return "Problem 3 - Largest Prime Factor";
        }


        virtual void init() override
        {
            factors.clear();
        }

        virtual void run(long &solution) override
        {
            euler::primeFactorize(testNumber, factors);
            solution = factors.back();
        }

        virtual void postProcess() override
        {
            //Output prime factors:
            std::cout << "Prime Factors:\n";
            for (long act : factors)
            {
                std::cout << act << "\n";
            }
        }
};
#endif
