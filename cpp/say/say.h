#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <cstdint>

namespace say
{
    std::string in_english(uint64_t n);

    std::string below_hundred(int n);

    std::string below_thousand(int n);
} // namespace say

#endif // SAY_H