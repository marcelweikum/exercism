#include "all_your_base.h"

#include <iostream>
#include <stdexcept>
#include <cmath>

namespace all_your_base
{
    int to_decimal(int from_base, const std::vector<unsigned int> numbers)
    {
        int sum{};
        int exp = numbers.size() - 1;

        for (unsigned int n : numbers)
        {
            if ((int)n >= from_base)
            {
                throw std::invalid_argument("Invalid number");
            }

            sum += n * std::pow(from_base, exp);
            --exp;
        }

        return sum;
    }

    std::vector<unsigned int> from_decimal(int to_base, int number)
    {
        std::vector<unsigned int> result;

        if (number == 0)
        {
            return {};
        }

        while (number > 0)
        {
            result.insert(result.begin(), number % to_base);
            number /= to_base;
        }
        return result;
    }

    std::vector<unsigned int> convert(int from_base, std::vector<unsigned int> numbers, int to_base)
    {
        if (from_base <= 1 || to_base <= 1)
        {
            throw std::invalid_argument("Invalid base");
        }

        return from_decimal(to_base, to_decimal(from_base, numbers));
    }

} // namespace all_your_base
