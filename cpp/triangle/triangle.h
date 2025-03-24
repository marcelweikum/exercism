#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle
{
    enum flavor
    {
        equilateral,
        isosceles,
        scalene
    };

    triangle::flavor kind(double a, double b, double c);
} // namespace triangle

#endif // TRIANGLE_H