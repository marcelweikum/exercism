#if !defined(ZEBRA_PUZZLE_H)
#define ZEBRA_PUZZLE_H

#include <string>

namespace zebra_puzzle
{

    struct Solution
    {
        std::string drinksWater;
        std::string ownsZebra;
    };

    struct House
    {
        std::string color;
        std::string nationality;
        std::string drink;
        std::string pet;
        std::string hobby;
    };

    Solution solve();

} // namespace zebra_puzzle

#endif // ZEBRA_PUZZLE_H
