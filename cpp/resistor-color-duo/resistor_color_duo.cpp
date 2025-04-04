#include "resistor_color_duo.h"

#include <unordered_map>

namespace resistor_color_duo
{

    std::unordered_map<std::string, std::string> codes{
        {"black", "0"},
        {"brown", "1"},
        {"red", "2"},
        {"orange", "3"},
        {"yellow", "4"},
        {"green", "5"},
        {"blue", "6"},
        {"violet", "7"},
        {"grey", "8"},
        {"white", "9"}};

    int value(std::vector<std::string> colors)
    {
        return std::stoi((codes.at(colors[0]) + codes.at(colors[1])));
    }

} // namespace resistor_color_duo
