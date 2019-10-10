#include <deque>
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
