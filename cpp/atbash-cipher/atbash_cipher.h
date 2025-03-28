#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

namespace atbash_cipher
{

    std::string encode(std::string message);
    std::string decode(std::string secret);

} // namespace atbash_cipher

#endif // ATBASH_CIPHER_H