#include "acronym.h"

namespace acronym
{

    std::string acronym(std::string word)
    {
        std::string result{};
        bool is_break = true;

        for (char c : word)
        {
            if (std::isalpha(c))
            {
                if (is_break)
                {
                    result += std::toupper(c);
                    is_break = false;
                }
            }
            else if (c != '\'')
            {
                is_break = true;
            }
        }

        return result;
    }

} // namespace acronym
