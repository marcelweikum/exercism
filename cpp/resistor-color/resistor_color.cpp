#include "resistor_color.h"

#include <stdexcept>
#include <algorithm>

namespace resistor_color
{
    std::vector<std::string> color_names = {
        "black", "brown", "red", "orange", "yellow",
        "green", "blue", "violet", "grey", "white"};

    int color_code(const std::string color)
    {
        auto it = std::find(color_names.begin(), color_names.end(), color);
        if (it != color_names.end())
        {
            return static_cast<int>(it - color_names.begin());
        }
        throw std::invalid_argument("Unknown color");
    }

    std::vector<std::string> colors()
    {
        return color_names;
    }

} // namespace resistor_color
