#ifndef EULER_PROBLEM_0009
#define EULER_PROBLEM_0009

#include <iostream>
#include "BaseProblem.h"
#include "lib/tools.h"

using namespace euler;

/**
 * @see https://projecteuler.net:
 *
 * Special Pythagorean triplet
 * Problem 9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
class Problem0009 : public BaseProblem
{
    protected:

        virtual string getTitle() override {
            return "Problem 9 - Special Pythagorean triplet";
        }

        virtual void run(long &solution) override
        {
            for (int c = 1000; c > 0; --c)
            {
                for (int b = c - 1; b > 0; --b)
                {
                    int a = 1000 - b - c;
                    if (a > 0 && a*a + b*b == c*c) {
                        cout << "Triplet: a + b + c = 1000 ==> " << a << " + " << b << " + " << c <<endl;
                        solution = a*b*c;
                        return;
                    }
                }
            }
        }
};
#endif
