#include "lasagna_master.h"

namespace lasagna_master
{
    int preparationTime(std::vector<std::string> layers, int time)
    {
        return layers.size() * time;
    }

    amount quantities(std::vector<std::string> ingredients)
    {
        amount needed{};
        for (size_t i{0}; i < ingredients.size(); i++)
        {
            if (ingredients[i] == "noodles")
            {
                needed.noodles += 50;
            }
            else if (ingredients[i] == "sauce")
            {
                needed.sauce += 0.2;
            }
        }
        return needed;
    }

    void addSecretIngredient(std::vector<std::string> &my_ingredients, std::vector<std::string> friends_ingredients)
    {
        my_ingredients.back() = friends_ingredients.back();
    }

    std::vector<double> scaleRecipe(std::vector<double> amounts, int portions)
    {
        std::vector<double> quantities{};
        for (size_t i{0}; i < amounts.size(); i++)
        {
            quantities.push_back(amounts[i] / 2 * portions);
        }
        return quantities;
    }

    void addSecretIngredient(std::vector<std::string> &my_ingredients, std::string aunties_whisper)
    {
        my_ingredients.back() = aunties_whisper;
    }

} // namespace lasagna_masters
