#include <stdbool.h>
#include <math.h>
#include "./mathlib.h"

bool isPrime(unsigned long nr)
{
    float border = sqrtf((double)nr);
    if (nr == 2)
        return true;
    if (nr % 2 == 0)
    {
        return false;
    }
    for (unsigned long i = 3; i <= border; i++)
    {
        if (nr % i == 0)
        {
            return false;
        }
    }
    return true;
}
