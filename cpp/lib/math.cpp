#include <deque>
#include <cmath>
#include "math.h"

void euler::primeFactorize(long nr, std::deque<long> &list)
{
    long fact = 2;
    while (nr > 1)
    {
        if (nr % fact == 0)
        {
            list.push_back(fact);
            nr = nr / fact;
        }
        else
        {
            fact++;
        }
    }
}


bool euler::isPrime(long nr)
{
    long border = std::ceil(std::sqrt(nr));
    if (nr < 2) return false;
    if (nr == 2) return true;
    if (nr % 2 == 0) return false;

    long test = 3;
    while (test <= border) {
        if (nr % test == 0) return false;
        test += 2;
    }
    return true;
}
