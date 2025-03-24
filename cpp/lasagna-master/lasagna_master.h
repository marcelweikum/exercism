#pragma once

#include <vector>
#include <string>

namespace lasagna_master
{

    struct amount
    {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string> layers, int time = 2);

    amount quantities(std::vector<std::string> ingredients);

    void addSecretIngredient(std::vector<std::string> &my_ingredients, std::vector<std::string> friends_ingredients);

    void addSecretIngredient(std::vector<std::string> &my_ingredients, std::string aunties_whisper);

    std::vector<double> scaleRecipe(std::vector<double> amounts, int portions);

} // namespace lasagna_master
