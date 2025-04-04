#include "eliuds_eggs.h"

namespace chicken_coop
{

    int positions_to_quantity(int eggs)
    {
        int count{};

        while (eggs > 0)
        {
            if (eggs & 1)
            {
                ++count;
            }
            eggs >>= 1;
        }
        return count;
    }

} // namespace chicken_coop
