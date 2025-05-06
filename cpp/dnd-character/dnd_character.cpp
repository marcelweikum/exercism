#include "dnd_character.h"

#include <random>
#include <array>
#include <numeric>
#include <algorithm>
#include <cmath>

namespace dnd_character
{

    int modifier(int n)
    {
        return std::floor((n - 10) / 2.0);
    }

    int ability()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 6);

        std::array<int, 4> rolls;
        for (int &r : rolls)
            r = dist(gen);

        return std::accumulate(rolls.begin(), rolls.end(), 0) - *std::min_element(rolls.begin(), rolls.end());
    }

} // namespace dnd_character
