#include "beer_song.h"

namespace beer_song
{

    std::string bottle_phrase(int count, bool capitalize = false)
    {
        std::string base;

        if (count == 0)
            base = "no more bottles";
        else if (count == 1)
            base = "1 bottle";
        else
            base = std::to_string(count) + " bottles";

        if (capitalize && count == 0)
            base[0] = std::toupper(base[0]);

        return base;
    }

    std::string verse(int n)
    {
        if (n == 0)
        {
            return bottle_phrase(n, true) + " of beer on the wall, " + bottle_phrase(n) + " of beer.\n" + "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }

        std::string action = (n == 1)
                                 ? "Take it down and pass it around"
                                 : "Take one down and pass it around";

        return bottle_phrase(n, true) + " of beer on the wall, " + bottle_phrase(n) + " of beer.\n" + action + ", " + bottle_phrase(n - 1) + " of beer on the wall.\n";
    }

    std::string sing(int from, int to)
    {
        std::string song;

        for (int i = from; i >= to; --i)
        {
            song += verse(i);
            if (i != to)
                song += "\n";
        }

        return song;
    }

} // namespace beer_song