#include "crypto_square.h"

namespace crypto_square
{

    cipher::cipher(std::string sentence)
    {
        this->sentence_ = sentence;
    }

    std::string cipher::normalized_cipher_text()
    {
        std::string result{};
        for (char c : sentence_)
        {
            if (isalnum(tolower(c)))
            {
                result += tolower(c);
            }
        }
        sentence_ = result;

        if (sentence_.empty())
        {
            return "";
        }

        size_t r{1};
        size_t c{1};

        while (r * c < sentence_.length() || c - r > 1)
        {
            if (c <= r)
            {
                ++c;
            }
            else
            {
                ++r;
            }
        }

        this->r_ = r;
        this->c_ = c;

        result = "";

        for (size_t col = 0; col < c_; ++col)
        {
            for (size_t row = 0; row < r_; ++row)
            {
                size_t index = row * c_ + col;
                if (index < sentence_.length())
                {
                    result += sentence_[index];
                }
                else
                {
                    result += " ";
                }
            }
            if (col < c_ - 1)
            {
                result += " ";
            }
        }
        return result;
    }
} // namespace crypto_square
