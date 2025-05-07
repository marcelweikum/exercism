#include "pig_latin.h"
#include <string>
#include <sstream>
#include <algorithm>

namespace pig_latin
{

    static bool is_vowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    static std::string translate_word(const std::string &w)
    {
        if (w.empty())
            return w;

        // rule 1
        if (is_vowel(w[0]) ||
            (w.rfind("xr", 0) == 0) ||
            (w.rfind("yt", 0) == 0))
        {
            return w + "ay";
        }

        // rule 3
        for (size_t i = 0; i + 1 < w.size(); ++i)
        {
            if (w[i] == 'q' && w[i + 1] == 'u' &&
                std::none_of(w.begin(), w.begin() + i,
                             [](char c)
                             { return is_vowel(c); }))
            {
                size_t cut = i + 2;
                return w.substr(cut) + w.substr(0, cut) + "ay";
            }
        }

        // rule 4
        size_t ypos = w.find('y', 1);
        if (ypos != std::string::npos &&
            std::none_of(w.begin(), w.begin() + ypos,
                         [](char c)
                         { return is_vowel(c); }))
        {
            return w.substr(ypos) + w.substr(0, ypos) + "ay";
        }

        // rule 2
        size_t first_vowel = 0;
        while (first_vowel < w.size() && !is_vowel(w[first_vowel]))
        {
            ++first_vowel;
        }
        if (first_vowel < w.size())
        {
            return w.substr(first_vowel) + w.substr(0, first_vowel) + "ay";
        }

        return w + "ay";
    }

    std::string translate(const std::string text)
    {
        std::istringstream iss(text);
        std::string word;
        std::string output;
        bool first = true;

        while (iss >> word)
        {
            if (!first)
                output += ' ';
            first = false;
            output += translate_word(word);
        }

        return output;
    }

} // namespace pig_latin
