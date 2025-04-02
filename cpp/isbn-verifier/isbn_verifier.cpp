#include "isbn_verifier.h"

namespace isbn_verifier
{

    bool is_valid(std::string isbn)
    {
        int counter{10};
        int sum{};
        int digits_seen{0};

        for (size_t i = 0; i < isbn.size(); ++i)
        {
            char c = isbn[i];

            if (c == '-')
                continue;

            if (std::isdigit(c))
            {
                sum += (c - '0') * counter;
            }
            else if (c == 'X')
            {
                if (counter != 1)
                {
                    return false;
                }
                sum += 10 * counter;
            }
            else
            {
                return false;
            }

            --counter;
            ++digits_seen;
        }

        return digits_seen == 10 && sum % 11 == 0;
    }

} // namespace isbn_verifier