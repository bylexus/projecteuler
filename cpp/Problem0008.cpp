#ifndef EULER_PROBLEM_0008
#define EULER_PROBLEM_0008

#include <iostream>
#include "BaseProblem.h"
#include "lib/tools.h"

using namespace euler;

/**
 * @see https://projecteuler.net:
 *
 * Largest product in a series
 * Problem 8
 *
 * The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
 *
 * (See Input file Problem0008-input.txt)
 *
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.
 * What is the value of this product?
 */
class Problem0008 : public BaseProblem
{
    protected:
        vector<int> digits;

        virtual string getTitle() override {
            return "Problem 8 - Largest product in a series";
        }

        void init() override {
            vector<string> lines;
            readLines("Problem0008-input.txt", lines);
            for (auto line : lines) {
                for (auto c : line) {
                    digits.push_back(c - 48);
                }
            }
        }


        virtual void run(long &solution) override
        {
            long maxProd = 0;
            unsigned int prodLength = 13;
            long prod;
            for (unsigned int i = prodLength - 1; i < digits.size(); ++i) {
                prod = 1;
                for (unsigned int d = i - (prodLength-1); d <= i; d++)
                {
                    prod *= digits[d];
                }
                maxProd = max(maxProd, prod);
            }
            solution = maxProd;
        }
};
#endif
