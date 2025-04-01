#include "binary.h"

#include <cmath>

namespace binary
{

    int convert(std::string b_number)
    {
        size_t size{b_number.size() - 1};
        int sum{};

        for (char c : b_number)
        {
            if (c == '1')
            {
                sum += pow(2, size);
            }
            else if (c != '0')
            {
                return 0;
            }
            --size;
        }
        return sum;
    }

} // namespace binary
