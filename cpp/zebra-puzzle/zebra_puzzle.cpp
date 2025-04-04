#include "zebra_puzzle.h"

#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

namespace zebra_puzzle
{
    // 2. The Englishman lives in the red house.
    bool satisfies_englishman_red(const std::array<House, 5> &houses)
    {
        for (const auto &h : houses)
        {
            if (h.nationality == "Englishman" && h.color == "red")
                return true;
        }
        return false;
    }
    // 3. The Spaniard owns the dog.
    bool satisfies_spaniard_owns_dog(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.nationality == "Spaniard" && h.pet == "dog")
                return true;
        }
        return false;
    }
    // 4. The person in the green house drinks coffee.
    bool satisfies_green_drinks_coffee(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.color == "green" && h.drink == "coffee")
                return true;
        }
        return false;
    }
    // 5. The Ukrainian drinks tea.
    bool satisfies_ukrainian_drinks_tea(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.nationality == "Ukrainian" && h.drink == "tea")
                return true;
        }
        return false;
    }
    // 6. The green house is immediately to the right of the ivory house.
    bool satisfies_green_right_of_ivory(const std::array<House, 5> &houses)
    {
        for (size_t i = 0; i < houses.size() - 1; ++i)
        {
            if (houses[i].color == "ivory" && houses[i + 1].color == "green")
            {
                return true;
            }
        }
        return false;
    }
    // 7. The snail owner likes to go dancing.
    bool satisfies_snail_dances(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.pet == "snail" && h.hobby == "dancing")
                return true;
        }
        return false;
    }
    // 8. The person in the yellow house is a painter.
    bool satisfies_yellow_paints(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.color == "yellow" && h.hobby == "painting")
                return true;
        }
        return false;
    }
    // 9. The person in the middle house drinks milk.
    bool satisfies_middle_drinks_milk(const std::array<House, 5> &houses)
    {
        return houses[2].drink == "milk";
    }
    // 10. The Norwegian lives in the first house.
    bool satisfies_norwegian_first(const std::array<House, 5> &houses)
    {
        return houses[0].nationality == "Norwegian";
    }
    // 11. The person who enjoys reading lives in the house next to the person with the fox.
    bool satisfies_fox_next_to_reader(const std::array<House, 5> &houses)
    {
        for (size_t i = 0; i < houses.size(); ++i)
        {
            if (houses[i].pet == "fox")
            {
                if (i > 0 && houses[i - 1].hobby == "reading")
                    return true;

                if (i < houses.size() - 1 && houses[i + 1].hobby == "reading")
                    return true;
            }
        }
        return false;
    }
    // 12. The painter's house is next to the house with the horse.
    bool satisfies_painter_next_to_horse(const std::array<House, 5> &houses)
    {
        for (size_t i = 0; i < houses.size(); ++i)
        {
            if (houses[i].hobby == "painting")
            {
                if (i > 0 && houses[i - 1].pet == "horse")
                    return true;

                if (i < houses.size() - 1 && houses[i + 1].pet == "horse")
                    return true;
            }
        }
        return false;
    }
    // 13. The person who plays football drinks orange juice.
    bool satisfies_football_orange_juice(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.hobby == "football" && h.drink == "orange juice")
                return true;
        }
        return false;
    }
    // 14. The Japanese person plays chess.
    bool satisfies_japanese_chess(const std::array<House, 5> &houses)
    {
        for (const House &h : houses)
        {
            if (h.nationality == "Japanese" && h.hobby == "chess")
                return true;
        }
        return false;
    }
    // 15. The Norwegian lives next to the blue house.
    bool satisfies_blue_next_to_norwegian(const std::array<House, 5> &houses)
    {
        for (size_t i = 0; i < houses.size(); ++i)
        {
            if (houses[i].nationality == "Norwegian")
            {
                if (i > 0 && houses[i - 1].color == "blue")
                    return true;

                if (i < houses.size() - 1 && houses[i + 1].color == "blue")
                    return true;
            }
        }
        return false;
    }

    Solution solve()
    {
        std::vector<std::string> colors = {"red", "green", "ivory", "yellow", "blue"};
        std::vector<std::string> nationalities = {"Englishman", "Spaniard", "Ukrainian", "Japanese", "Norwegian"};
        std::vector<std::string> drinks = {"coffee", "tea", "milk", "orange juice", "water"};
        std::vector<std::string> pets = {"dog", "snail", "fox", "horse", "zebra"};
        std::vector<std::string> hobbies = {"dancing", "painting", "reading", "football", "chess"};

        // 1. There are five houses.
        std::array<House, 5> houses;

        Solution solution;

        std::function<bool(int)> assign = [&](int category) -> bool
        {
            if (category == 0)
            {
                // colors
                std::sort(colors.begin(), colors.end());
                do
                {
                    for (int i = 0; i < 5; ++i)
                        houses[i].color = colors[i];

                    if (!satisfies_green_right_of_ivory(houses))
                        continue;

                    if (assign(category + 1))
                        return true;
                } while (std::next_permutation(colors.begin(), colors.end()));
            }
            else if (category == 1)
            {
                // nationalities
                std::sort(nationalities.begin(), nationalities.end());
                do
                {
                    for (int i = 0; i < 5; ++i)
                        houses[i].nationality = nationalities[i];

                    if (!satisfies_norwegian_first(houses))
                        continue;
                    if (!satisfies_englishman_red(houses))
                        continue;
                    if (!satisfies_blue_next_to_norwegian(houses))
                        continue;

                    if (assign(category + 1))
                        return true;
                } while (std::next_permutation(nationalities.begin(), nationalities.end()));
            }
            else if (category == 2)
            {
                // drinks
                std::sort(drinks.begin(), drinks.end());
                do
                {
                    for (int i = 0; i < 5; ++i)
                        houses[i].drink = drinks[i];

                    if (!satisfies_green_drinks_coffee(houses))
                        continue;
                    if (!satisfies_ukrainian_drinks_tea(houses))
                        continue;
                    if (!satisfies_middle_drinks_milk(houses))
                        continue;

                    if (assign(category + 1))
                        return true;
                } while (std::next_permutation(drinks.begin(), drinks.end()));
            }
            else if (category == 3)
            {
                // pets
                std::sort(pets.begin(), pets.end());
                do
                {
                    for (int i = 0; i < 5; ++i)
                        houses[i].pet = pets[i];

                    if (!satisfies_spaniard_owns_dog(houses))
                        continue;

                    if (assign(category + 1))
                        return true;
                } while (std::next_permutation(pets.begin(), pets.end()));
            }
            else if (category == 4)
            {
                // hobbies
                std::sort(hobbies.begin(), hobbies.end());
                do
                {
                    for (int i = 0; i < 5; ++i)
                        houses[i].hobby = hobbies[i];

                    if (!satisfies_yellow_paints(houses))
                        continue;
                    if (!satisfies_football_orange_juice(houses))
                        continue;
                    if (!satisfies_japanese_chess(houses))
                        continue;
                    if (!satisfies_snail_dances(houses))
                        continue;
                    if (!satisfies_fox_next_to_reader(houses))
                        continue;
                    if (!satisfies_painter_next_to_horse(houses))
                        continue;

                    for (int i = 0; i < 5; ++i)
                    {
                        if (houses[i].drink == "water")
                            solution.drinksWater = houses[i].nationality;
                        if (houses[i].pet == "zebra")
                            solution.ownsZebra = houses[i].nationality;
                    }

                    return true;
                } while (std::next_permutation(hobbies.begin(), hobbies.end()));
            }
            return false;
        };

        assign(0);
        return solution;
    }

} // namespace zebra_puzzle
