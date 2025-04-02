#include "largest_series_product.h"

#include <stdexcept>

namespace largest_series_product
{

    int largest_product(std::string input, int span)
    {
        if (span < 0 || (size_t)span > input.size())
        {
            throw std::domain_error("Invalid span");
        }

        int biggest_sum{};

        for (int i{}; i <= (int)input.size() - span; ++i)
        {
            int sum{1};

            for (int j{}; j < span; ++j)
            {
                char c = input[i + j];
                if (!std::isdigit(c))
                {
                    throw std::domain_error("Non-digit character");
                }

                sum *= c - '0';
            }

            if (sum > biggest_sum)
            {
                biggest_sum = sum;
            }
        }
        return biggest_sum;
    }

} // namespace largest_series_product