#include "roman_numerals.h"

#include <utility>
#include <vector>

namespace roman_numerals
{

    std::string convert(int number)
    {
        std::vector<std::pair<int, std::string>> characters{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        std::string result;

        for (const auto &[value, symbol] : characters)
        {
            while (number >= value)
            {
                result += symbol;
                number -= value;
            }
        }
        return result;
    }

} // namespace roman_numerals
