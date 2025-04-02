#include "darts.h"

namespace darts
{

    int score(double x, double y)
    {
        double squared{x * x + y * y};

        if (squared <= 1) // 1^2
        {
            return 10;
        }
        else if (squared <= 25) // 5^2
        {
            return 5;
        }
        else if (squared <= 100) // 10^2
        {
            return 1;
        }
        else // out
        {
            return 0;
        }
    }

} // namespace darts