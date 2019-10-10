#ifndef EULER_PROBLEM_0003
#define EULER_PROBLEM_0003

#include <iostream>
#include <deque>
#include "BaseProblem.cpp"

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
    long biggest{0};

    virtual void init() override
    {
        biggest = 0;
        factors.clear();
    }

    void primeFactorize(long nr, std::deque<long> &list, long &biggest)
    {
        long act = 2;
        while (nr > 1)
        {
            if (nr % act == 0)
            {
                list.push_back(act);
                nr = nr / act;
                if (act > biggest)
                    biggest = act;
            }
            else
            {
                act++;
            }
        }
    }

    virtual void run(long &solution) override
    {

        primeFactorize(testNumber, factors, biggest);
        solution = biggest;
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

public:
    Problem0003() : BaseProblem("Problem 3 - Largest Prime Factor") {}
};
#endif
