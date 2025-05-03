#include <algorithm>
#include "kindergarten_garden.h"

namespace kindergarten_garden
{

    std::array<Plants, 4> plants(std::string rows, std::string name)
    {
        std::array<std::string, 12> kids{
            "Alice", "Bob", "Charlie", "David",
            "Eve", "Fred", "Ginny", "Harriet",
            "Ileana", "Joseph", "Kincaid", "Larry"};

        auto it = std::find(kids.begin(), kids.end(), name);
        if (it == kids.end())
        {
            return {};
        }
        size_t index = std::distance(kids.begin(), it);

        auto delim = rows.find('\n');
        std::string row1 = rows.substr(0, delim);
        std::string row2 = rows.substr(delim + 1);

        std::array<Plants, 4> result;
        int pos = index * 2;
        result[0] = define_plant(row1[pos]);
        result[1] = define_plant(row1[pos + 1]);
        result[2] = define_plant(row2[pos]);
        result[3] = define_plant(row2[pos + 1]);

        return result;
    }

    kindergarten_garden::Plants define_plant(char letter)
    {
        switch (letter)
        {
        case 'G':
            return kindergarten_garden::grass;
            break;
        case 'C':
            return kindergarten_garden::clover;
            break;
        case 'R':
            return kindergarten_garden::radishes;
            break;
        case 'V':
            return kindergarten_garden::violets;
            break;
        }
        return kindergarten_garden::grass;
    }

} // namespace kindergarten_garden
