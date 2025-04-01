#include "isogram.h"

#include <unordered_set>

namespace isogram
{

    bool is_isogram(std::string word)
    {
        std::unordered_set<char> seen;
        for (char c : word)
        {
            if (c == ' ' || c == '-')
            {
                continue;
            }

            if (seen.count(tolower(c)))
            {
                return false;
            }
            else
            {
                seen.insert(tolower(c));
            }
        }
        return true;
    }

} // namespace isogram
