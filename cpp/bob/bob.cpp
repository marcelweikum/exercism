#include "bob.h"

#include <algorithm>

namespace bob
{

    std::string hey(std::string sentence)
    {
        sentence = std::string(
            sentence.begin(),
            std::find_if_not(sentence.rbegin(), sentence.rend(),
                             [](unsigned char c)
                             { return std::isspace(c); })
                .base());

        size_t size{sentence.size() - 1};
        bool yelling{true};
        bool has_letters{false};

        for (size_t i{}; i < size; ++i)
        {
            if (std::isalpha(sentence[i]))
            {
                has_letters = true;
                if (!std::isupper(sentence[i]))
                {
                    yelling = false;
                    break;
                }
            }
        }

        if (!has_letters)
        {
            yelling = false;
        }

        if (sentence[size] == '?')
        {
            if (yelling)
            {
                return "Calm down, I know what I'm doing!";
            }
            return "Sure.";
        }
        else if (yelling)
        {
            return "Whoa, chill out!";
        }
        else if (sentence == "")
        {
            return "Fine. Be that way!";
        }
        return "Whatever.";
    }

} // namespace bob
