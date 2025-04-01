#include "armstrong_numbers.h"

#include <string>
#include <cmath>

namespace armstrong_numbers
{

    bool is_armstrong_number(int number)
    {
        std::string n{std::to_string(number)};
        size_t exponent{n.size()};
        int sum{};

        for (char c : n)
        {
            sum += pow(c - '0', exponent);
        }
        return number == sum;
    }

} // namespace armstrong_numbers
