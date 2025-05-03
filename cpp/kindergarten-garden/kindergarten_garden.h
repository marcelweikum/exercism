#pragma once

#include <array>
#include <string>

namespace kindergarten_garden
{

    enum Plants
    {
        clover,
        grass,
        violets,
        radishes
    };

    std::array<kindergarten_garden::Plants, 4> plants(std::string rows, std::string name);

    kindergarten_garden::Plants define_plant(char letter);

} // namespace kindergarten_garden
