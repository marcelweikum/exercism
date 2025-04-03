#include "high_scores.h"

#include <algorithm>

namespace arcade
{

    std::vector<int> HighScores::list_scores()
    {
        return scores;
    }

    int HighScores::latest_score()
    {
        return scores[scores.size() - 1];
    }

    int HighScores::personal_best()
    {
        int best{};

        for (int n : scores)
        {
            if (n > best)
            {
                best = n;
            }
        }
        return best;
    }

    std::vector<int> HighScores::top_three()
    {
        std::vector<int> three = scores;
        std::sort(three.begin(), three.end(), std::greater<int>());
        three = std::vector<int>{three.begin(), three.size() >= 3 ? three.begin() + 3 : three.begin() + three.size()};
        return three;
    }

} // namespace arcade
