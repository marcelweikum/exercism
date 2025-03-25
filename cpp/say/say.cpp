#include "say.h"

#include <stdexcept>
#include <vector>

namespace say
{
    std::string in_english(uint64_t n)
    {
        std::string result{};

        if (n >= 999'999'999'999)
            throw std::domain_error("Out of range");

        if (n == 0)
            return "zero";

        uint64_t billions = n / 1'000'000'000 % 1000;
        uint64_t millions = n / 1'000'000 % 1000;
        uint64_t thousands = n / 1'000 % 1000;
        uint64_t rest = n % 1000;

        if (billions)
            result += below_thousand(billions) + " billion";
        if (millions)
            result += (result.empty() ? "" : " ") + below_thousand(millions) + " million";
        if (thousands)
            result += (result.empty() ? "" : " ") + below_thousand(thousands) + " thousand";
        if (rest)
            result += (result.empty() ? "" : " ") + below_thousand(rest);
        return result;
    }

    std::string below_hundred(int n)
    {
        std::vector<std::string> units{"zero", "one", "two", "three", "four", "five",
                                       "six", "seven", "eight", "nine", "ten",
                                       "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                       "sixteen", "seventeen", "eighteen", "nineteen"};

        std::vector<std::string> tens{"", "", "twenty", "thirty", "forty", "fifty",
                                      "sixty", "seventy", "eighty", "ninety"};

        if (n < 20)
            return units[n];

        int ten{n / 10};
        int unit{n % 10};

        if (unit == 0)
        {
            return tens[ten];
        }
        else
        {
            return tens[ten] + "-" + units[unit];
        }
    }

    std::string below_thousand(int n)
    {
        std::string result{};

        if (n < 100)
            return below_hundred(n);

        int hundred = n / 100;
        int rest = n % 100;

        result = below_hundred(hundred) + " hundred";
        if (rest > 0)
        {
            result += " " + below_hundred(rest);
        }

        return result;
    }
} // namespace say
