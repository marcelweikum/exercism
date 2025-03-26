#include "sum_of_multiples.h"

#include <unordered_set>

namespace sum_of_multiples
{

    int to(std::vector<int> items, int level)
    {
        std::unordered_set<int> numbers{};
        int sum{};

        for (int item : items)
        {
            if (item == 0)
                continue;

            for (int j{item}; j < level; j += item)
            {
                numbers.insert(j);
            }
        }

        for (int number : numbers)
        {
            sum += number;
        }
        return sum;
    }

} // namespace sum_of_multiples
