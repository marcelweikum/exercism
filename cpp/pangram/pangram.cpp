#include "pangram.h"

#include <cctype>

namespace pangram
{

    bool is_pangram(std::string sentence)
    {
        std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        bool is_present{false};
        for (char a : alphabet)
        {
            is_present = false;
            for (char s : sentence)
            {
                if (toupper(s) == a)
                {
                    is_present = true;
                }
            }
            if (is_present == false)
            {
                return false;
            }
        }
        return true;
    }

} // namespace pangram
