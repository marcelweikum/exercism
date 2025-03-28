#include "food_chain.h"

#include <vector>

namespace food_chain
{

    std::string verse(int line)
    {
        const std::vector<std::string> animals{
            "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
        const std::vector<std::string> reactions{
            "I don't know why she swallowed the fly. Perhaps she'll die.\n",
            "It wriggled and jiggled and tickled inside her.\n",
            "How absurd to swallow a bird!\n",
            "Imagine that, to swallow a cat!\n",
            "What a hog, to swallow a dog!\n",
            "Just opened her throat and swallowed a goat!\n",
            "I don't know how she swallowed a cow!\n",
            "She's dead, of course!\n"};

        std::string result;

        int i = line - 1;

        result += "I know an old lady who swallowed a " + animals[i] + ".\n";

        if (animals[i] == "horse")
        {
            result += reactions[i];
            return result;
        }

        if (i > 0)
        {
            result += reactions[i];
        }

        for (int j = i; j > 0; --j)
        {
            result += "She swallowed the " + animals[j] + " to catch the " + animals[j - 1];

            if (animals[j - 1] == "spider")
            {
                result += " that wriggled and jiggled and tickled inside her.\n";
            }
            else
            {
                result += ".\n";
            }
        }

        result += reactions[0];

        return result;
    }

    std::string verses(int from, int to)
    {
        std::string result{};

        for (; from <= to; ++from)
        {
            result += verse(from) + "\n";
        }
        return result;
    }

    std::string sing()
    {
        return verses(1, 8);
    }

} // namespace food_chain
