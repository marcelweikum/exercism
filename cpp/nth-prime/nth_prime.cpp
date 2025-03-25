#include "nth_prime.h"

#include <vector>
#include <stdexcept>

namespace nth_prime
{
    bool is_prime(int number)
    {
        if (number <= 1)
            return false;
        for (int i{2}; i * i <= number; ++i)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    int nth(int n)
    {
        if (n <= 0)
            throw std::domain_error("There is no zeroth prime");

        int count{};
        int number{1};

        while (count < n)
        {
            ++number;
            if (is_prime(number))
                ++count;
        }
        return number;
    }
} // namespace nth_prime
