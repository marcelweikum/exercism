#include "hamming.h"

#include <stdexcept>

namespace hamming
{
    int compute(std::string first, std::string second)
    {
        int errors{};

        if (first.size() != second.size())
        {
            throw std::domain_error("different sizes");
        }
        else
        {
            for (size_t i{}; i < first.size(); i++)
            {
                if (first[i] != second[i])
                {
                    errors++;
                }
            }
        }
        return errors;
    }
} // namespace hamming
