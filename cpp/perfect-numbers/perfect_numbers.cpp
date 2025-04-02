#include "perfect_numbers.h"

#include <vector>
#include <stdexcept>

namespace perfect_numbers
{

    classification classify(int number)
    {
        if (number <= 0)
        {
            throw std::domain_error("Number is invalid");
        }

        int sum{};

        for (int i{1}; i < number; ++i)
        {
            if (number % i != number && number % i == 0)
            {
                sum += i;
            }
        }
        if (number == sum)
        {
            return classification::perfect;
        }
        else if (number < sum)
        {
            return classification::abundant;
        }
        else
        {
            return classification::deficient;
        }
    }

} // namespace perfect_numbers
