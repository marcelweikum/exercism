#include "binary_search.h"

#include <stdexcept>

namespace binary_search
{

    int find(std::vector<int> list, int number)
    {
        int left{0};
        int right = list.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (list[mid] == number)
                return mid;

            if (number < list[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        throw std::domain_error("Number not found");
    }

} // namespace binary_search
