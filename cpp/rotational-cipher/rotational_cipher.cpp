#include "rotational_cipher.h"

namespace rotational_cipher
{

    std::string rotate(std::string s, int r)
    {
        std::string result{};

        for (char c : s)
            if (isalpha(c))
            {
                if (std::isupper(c))
                {
                    result += 'A' + (c - 'A' + r) % 26;
                }
                else if (std::islower(c))
                {
                    result += 'a' + (c - 'a' + r) % 26;
                }
            }
            else
            {
                result += c;
            }
        return result;
    }

} // namespace rotational_cipher
