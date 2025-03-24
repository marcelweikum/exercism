#include "reverse_string.h"

namespace reverse_string
{
    std::string reverse_string(std::string string)
    {
        // std::string new_string{};
        // for (size_t i{string.size()}; i > 0; i--)
        // {
        //     new_string.push_back(string[i - 1]);
        // }
        // return new_string;

        return std::string(string.rbegin(), string.rend());
    }
} // namespace reverse_string
