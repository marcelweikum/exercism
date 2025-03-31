#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>

namespace crypto_square
{

    class cipher
    {
    public:
        cipher(std::string sentence);
        std::string normalized_cipher_text();

    private:
        std::string sentence_;
        size_t c_;
        size_t r_;
    };

} // namespace crypto_square

#endif // CRYPTO_SQUARE_H