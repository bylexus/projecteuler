#ifndef EULER_MATH_H
#define EULER_MATH_H
#include <deque>

namespace euler
{
    void primeFactorize(long nr, std::deque<long> &list);
    bool isPrime(long nr);
}

#endif
