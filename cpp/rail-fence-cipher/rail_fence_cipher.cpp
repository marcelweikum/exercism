#include "rail_fence_cipher.h"
#include <vector>

namespace rail_fence_cipher
{

    std::string encode(const std::string &plaintext, int num_rails)
    {
        if (num_rails <= 1 || plaintext.empty())
        {
            return plaintext;
        }

        std::vector<std::string> rails(num_rails);
        int rail = 0;
        int direction = 1;

        for (char ch : plaintext)
        {
            rails[rail] += ch;

            if (rail == 0)
            {
                direction = 1;
            }
            else if (rail == num_rails - 1)
            {
                direction = -1;
            }

            rail += direction;
        }

        std::string encoded;
        for (const auto &row : rails)
        {
            encoded += row;
        }

        return encoded;
    }

    std::string decode(const std::string &ciphertext, int num_rails)
    {
        if (num_rails <= 1 || ciphertext.empty())
        {
            return ciphertext;
        }

        int length = ciphertext.length();
        std::vector<std::vector<char>> grid(num_rails, std::vector<char>(length, '\0'));

        int rail = 0;
        int direction = 1;

        for (int i = 0; i < length; ++i)
        {
            grid[rail][i] = '?';

            if (rail == 0)
            {
                direction = 1;
            }
            else if (rail == num_rails - 1)
            {
                direction = -1;
            }

            rail += direction;
        }

        int index = 0;
        for (int r = 0; r < num_rails; ++r)
        {
            for (int c = 0; c < length; ++c)
            {
                if (grid[r][c] == '?' && index < length)
                {
                    grid[r][c] = ciphertext[index++];
                }
            }
        }

        std::string decoded;
        rail = 0;
        direction = 1;

        for (int i = 0; i < length; ++i)
        {
            decoded += grid[rail][i];

            if (rail == 0)
            {
                direction = 1;
            }
            else if (rail == num_rails - 1)
            {
                direction = -1;
            }

            rail += direction;
        }

        return decoded;
    }

} // namespace rail_fence_cipher
