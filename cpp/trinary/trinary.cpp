#include "trinary.h"

#include <cmath>

namespace trinary
{

    int to_decimal(std::string trinary)
    {
        int sum{};

        for (size_t i{}; i < trinary.size(); ++i)
        {
            if (isalpha(trinary[i]))
            {
                break;
            }
            sum += (trinary[i] - '0') * std::pow(3, (trinary.size() - i - 1));
        }

        return sum;
    }

} // namespace trinary
