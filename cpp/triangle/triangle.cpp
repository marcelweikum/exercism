#include "triangle.h"
#include <stdexcept>

namespace triangle
{
    flavor kind(double a, double b, double c)
    {
        if (a > 0 and b > 0 and c > 0 and a + b >= c and b + c >= a and a + c >= b)
        {
            if (a == b and a == c and b == c)
            {
                return flavor::equilateral;
            }
            else if (a == b or a == c or b == c)
            {
                return flavor::isosceles;
            }
            else
            {
                return flavor::scalene;
            }
        }
        else
        {
            throw std::domain_error("not a triangle");
        }
    }
} // namespace triangle
