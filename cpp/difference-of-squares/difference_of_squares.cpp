#include "difference_of_squares.h"

namespace difference_of_squares
{

    int square_of_sum(int number)
    {
        int sum{};
        for (int n{1}; n <= number; n++)
        {
            sum += n;
        }
        return sum * sum;
    }

    int sum_of_squares(int number)
    {
        int sum{};
        for (int n{1}; n <= number; n++)
        {
            sum += n * n;
        }
        return sum;
    }

    int difference(int number)
    {
        return square_of_sum(number) - sum_of_squares(number);
    }

} // namespace difference_of_squares
