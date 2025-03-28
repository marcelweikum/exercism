#include "atbash_cipher.h"

#include <utility>

namespace atbash_cipher
{
    std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};

    std::string encode(std::string message)
    {
        std::string result{};
        int count{};

        for (size_t i{}; i < message.size(); ++i)
        {
            char c = tolower(message[i]);

            if (!std::isalpha(c) && !std::isdigit(c))
            {
                continue;
            }

            if (count > 0 && count % 5 == 0)
            {
                result += ' ';
            }

            if (std::isalpha(c))
            {
                result += alphabet[25 - (c - 'a')];
            }
            else
            {
                result += c;
            }
            ++count;
        }
        return result;
    }

    std::string decode(std::string secret)
    {
        std::string result{};

        for (size_t i{}; i < secret.size(); ++i)
        {
            char c = tolower(secret[i]);
            if (!std::isalpha(c) && !std::isdigit(c))
            {
                continue;
            }

            if (std::isalpha(c))
            {
                result += alphabet[25 - (c - 'a')];
            }
            else
            {
                result += c;
            }
        }
        return result;
    }

} // namespace atbash_cipher
