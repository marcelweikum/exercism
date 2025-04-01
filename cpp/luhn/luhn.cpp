#include "luhn.h"

namespace luhn
{

    bool valid(std::string number)
    {
        int sum{};
        int counter{0};

        for (int i = number.size() - 1; i >= 0; --i)
        {
            if (number[i] == ' ')
            {
                continue;
            }
            else if (!isdigit(number[i]))
            {
                return false;
            }

            int n{number[i] - '0'};

            if (counter % 2 == 1)
            {
                n *= 2;
                if (n > 9)
                {
                    n -= 9;
                }
            }
            sum += n;
            ++counter;
        }
        if (counter <= 1)
        {
            return false;
        }
        return sum % 10 == 0;
    }

} // namespace luhn
