#include "diamond.h"
#include <string>
#include <vector>
#include <algorithm>

namespace diamond
{

    std::vector<std::string> rows(char c)
    {
        const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::vector<std::string> result;

        size_t last_index = c - 'A';
        size_t total_rows = last_index * 2 + 1;

        for (size_t i = 0; i < total_rows; ++i)
        {
            size_t row_index = std::min(i, total_rows - i - 1);
            char letter = alphabet[row_index];

            size_t outer_spaces = last_index - row_index;
            size_t inner_spaces = row_index == 0 ? 0 : (row_index * 2 - 1);

            std::string row(outer_spaces, ' ');
            row += letter;
            if (row_index > 0)
            {
                row.append(inner_spaces, ' ');
                row += letter;
            }
            row.append(outer_spaces, ' ');

            result.push_back(row);
        }

        return result;
    }

} // namespace diamond
