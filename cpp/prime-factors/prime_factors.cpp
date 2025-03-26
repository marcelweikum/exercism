#include "prime_factors.h"

namespace prime_factors
{

    std::vector<long long> of(long number)
    {
        std::vector<long long> numbers{};

        for (long i{2}; i <= number;)
        {
            if (number % i == 0)
            {
                numbers.push_back(i);
                number = number / i;
            }
            else
            {
                ++i;
            }
        }
        return numbers;
    }

} // namespace prime_factors
