#include "knapsack.h"
#include <algorithm>

namespace knapsack
{

    int maximum_value(int weight, std::vector<Item> items)
    {
        std::vector<int> table(weight + 1, 0);

        for (const auto &item : items)
        {
            for (int w = weight; w >= item.weight; --w)
            {
                table[w] = std::max(table[w], table[w - item.weight] + item.value);
            }
        }

        return table[weight];
    }

} // namespace knapsack