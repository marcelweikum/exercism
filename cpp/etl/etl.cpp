#include "etl.h"

#include <cctype>

namespace etl
{

    std::map<char, int> transform(std::map<int, std::vector<char>> old_map)
    {
        std::map<char, int> new_map;

        for (const auto &[score, letters] : old_map)
        {
            for (char letter : letters)
            {
                new_map[std::tolower(letter)] = score;
            }
        }
        return new_map;
    }

} // namespace etl
