#if !defined(ALL_YOUR_BASE_H)
#define ALL_YOUR_BASE_H

#include <vector>

namespace all_your_base
{
    int to_decimal(int from_base, std::vector<unsigned int> numbers);
    std::vector<unsigned int> from_decimal(int to_base, int number);

    std::vector<unsigned int> convert(int from_base, std::vector<unsigned int> numbers, int to_base);

} // namespace all_your_base

#endif // ALL_YOUR_BASE_H