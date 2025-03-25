#include "sieve.h"

namespace sieve
{
    std::vector<int> primes(int n)
    {
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p <= n; ++p)
        {
            if (is_prime[p])
            {
                for (int i = p * p; i <= n; i += p)
                {
                    is_prime[i] = false;
                }
            }
        }

        std::vector<int> primes;
        for (int i = 2; i <= n; ++i)
        {
            if (is_prime[i])
                primes.push_back(i);
        }

        return primes;
    }
} // namespace sieve
