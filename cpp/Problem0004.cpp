#ifndef EULER_PROBLEM_0004
#define EULER_PROBLEM_0004

#include <iostream>
#include <deque>
#include "BaseProblem.h"

/**
 * @see https://projecteuler.net:
 *
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product
 * of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
class Problem0004 : public BaseProblem
{
    protected:
        long maxPalindrome;
        long maxI;
        long maxJ;

        virtual string getTitle() override {
            return "Problem 4 - Largest palindrome product";
        }


        virtual void init() override
        {
            maxPalindrome = 0;
            maxI = 0;
            maxJ = 0;
        }

        bool isPalindrome(long nr)
        {
            long p = 0;
            long n = nr;
            while (n > 0)
            {
                p = 10 * p + n % 10;
                n = n / 10;
            }
            return nr == p;
        }

        virtual void run(long &solution) override
        {

            /**
             * Idea:
             * 1. build products of 3-digit numbers from 100 to 999, beginning at the top.
             * 2. Check if the product is a palindrome.
             * 3. Check if we found one that was bigger before. remember max value.
             */

            for (int i = 999; i >= 100; i--)
            {
                for (int j = i; j >= 100; j--)
                {
                    if (isPalindrome(i * j))
                    {
                        if (maxPalindrome < i * j)
                        {
                            maxPalindrome = i * j;
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
            solution = maxPalindrome;
        }

        virtual void postProcess() override
        {
            std::cout << "Palindrome found: "
                << maxPalindrome
                << ", product of "
                << maxI
                << " * "
                << maxJ
                << "\n";
        }
};
#endif
