#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture
{

    int steps(int number)
    {
        int steps{};

        if (number <= 0)
        {
            throw std::domain_error("invalid number");
        }

        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number /= 2;
                steps++;
            }
            else
            {
                number *= 3;
                number += 1;
                steps++;
            }
        }
        return steps;
    }
} // namespace collatz_conjecture
