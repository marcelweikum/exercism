#include "grains.h"

namespace grains
{

    unsigned long long square(int number)
    {
        unsigned long long sum{1};
        while (number > 1)
        {
            sum *= 2;
            number--;
        }
        return sum;
    }

    unsigned long long total()
    {
        unsigned long long total{0};
        for (int i{1}; i <= 64; i++)
        {
            total += square(i);
        }
        return total;
    }

} // namespace grains
