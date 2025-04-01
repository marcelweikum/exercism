#include "hexadecimal.h"

#include <cmath>

namespace hexadecimal
{

    int convert(std::string h_number)
    {

        size_t size{h_number.size() - 1};
        int sum{};
        int value{};

        for (char c : h_number)
        {
            if (isdigit(c))
            {
                value = c - '0';
            }
            else if (c >= 'a' && c <= 'f')
            {
                value = c - 'a' + 10;
            }
            else
            {
                return 0;
            }
            sum += value * pow(16, size);
            --size;
        }
        return sum;
    }

} // namespace hexadecimal
