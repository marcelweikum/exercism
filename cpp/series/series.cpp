#include "series.h"

#include <stdexcept>

namespace series
{

    std::vector<std::string> slice(std::string input, size_t length)
    {
        if (input.size() < length || length <= 0)
            throw std::domain_error("Invalid length");

        std::vector<std::string> result{};

        for (size_t i{0}; (i + length) <= input.size(); ++i)
        {
            result.push_back(std::string(input.begin() + i, input.begin() + i + length));
        }
        return result;
    }

} // namespace series
