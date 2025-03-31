#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram
{

    anagram::anagram(std::string word)
    {
        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });

        this->word_ = word;
        this->sorted_word_ = word_;
        std::sort(this->sorted_word_.begin(), this->sorted_word_.end());
    }

    std::unordered_set<std::string> anagram::matches(std::unordered_set<std::string> list)
    {
        std::unordered_set<std::string> result;
        for (const std::string &guess : list)
        {
            std::string small_guess = guess;
            std::transform(small_guess.begin(), small_guess.end(), small_guess.begin(),
                           [](unsigned char c)
                           { return std::tolower(c); });

            if (small_guess == word_)
            {
                continue;
            }

            std::string sorted_guess = small_guess;
            std::sort(sorted_guess.begin(), sorted_guess.end());

            if (sorted_guess == sorted_word_)
            {
                result.insert(guess);
            }
        }
        return result;
    }

} // namespace anagram
