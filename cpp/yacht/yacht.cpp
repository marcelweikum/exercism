#include "yacht.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace yacht
{
    int calc_nums(std::vector<int> dices, int num)
    {
        int sum{};

        for (int n : dices)
        {
            if (n == num)
                sum += n;
        }
        return sum;
    }

    int score(std::vector<int> dices, std::string category)
    {
        if (category == "yacht")
        {
            int first = dices[0];

            bool all_same = std::all_of(
                dices.begin() + 1,
                dices.end(),
                [first](int die)
                { return die == first; });

            return all_same ? 50 : 0;
        }
        else if (category == "big straight")
        {
            auto sorted = dices;
            std::sort(sorted.begin(), sorted.end());
            const std::vector<int> target = {2, 3, 4, 5, 6};
            return (sorted == target) ? 30 : 0;
        }
        else if (category == "little straight")
        {
            auto sorted = dices;
            std::sort(sorted.begin(), sorted.end());
            const std::vector<int> target = {1, 2, 3, 4, 5};
            return (sorted == target) ? 30 : 0;
        }
        else if (category == "four of a kind")
        {
            auto sorted = dices;
            std::sort(sorted.begin(), sorted.end());
            if (sorted[0] == sorted[3])
                return sorted[0] * 4;
            else if (sorted[1] == sorted[4])
                return sorted[1] * 4;
            else
                return 0;
        }
        else if (category == "full house")
        {
            auto sorted = dices;
            std::sort(sorted.begin(), sorted.end());
            bool pattern1 = (sorted[0] == sorted[1] && sorted[2] == sorted[4] && sorted[1] != sorted[2]);
            bool pattern2 = (sorted[0] == sorted[2] && sorted[3] == sorted[4] && sorted[2] != sorted[3]);
            if (pattern1 || pattern2)
                return std::accumulate(dices.begin(), dices.end(), 0);
            else
                return 0;
        }
        else if (category == "sixes")
        {
            return calc_nums(dices, 6);
        }
        else if (category == "fives")
        {
            return calc_nums(dices, 5);
        }
        else if (category == "fours")
        {
            return calc_nums(dices, 4);
        }
        else if (category == "threes")
        {
            return calc_nums(dices, 3);
        }
        else if (category == "twos")
        {
            return calc_nums(dices, 2);
        }
        else if (category == "ones")
        {
            return calc_nums(dices, 1);
        }
        else if (category == "choice")
        {
            return std::accumulate(dices.begin(), dices.end(), 0);
        }

        return 0;
    }

} // namespace yacht
