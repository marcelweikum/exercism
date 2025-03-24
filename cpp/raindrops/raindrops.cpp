#include "raindrops.h"

namespace raindrops
{
    std::string convert(int number)
    {
        std::string result{};
        if (number % 3 != 0 && number % 5 != 0 && number % 7 != 0)
        {
            return std::to_string(number);
        }
        if (number % 3 == 0)
        {
            result += "Pling";
        }
        if (number % 5 == 0)
        {
            result += "Plang";
        }
        if (number % 7 == 0)
        {
            result += "Plong";
        }
        return result;
    }
} // namespace raindrops
