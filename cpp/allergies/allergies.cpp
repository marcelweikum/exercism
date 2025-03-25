#include "allergies.h"

namespace allergies
{
    allergy_test::allergy_test(int i)
    {
        static const std::vector<std::string> allergy_list = {
            "eggs", "peanuts", "shellfish", "strawberries",
            "tomatoes", "chocolate", "pollen", "cats"};

        for (int bit = 0; bit < 8; ++bit)
        {
            if (i & (1 << bit))
            {
                allergies_.insert(allergy_list[bit]);
            }
        }
    }

    bool allergy_test::is_allergic_to(std::string item)
    {
        return allergies_.find(item) != allergies_.end();
    }

    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        return allergies_;
    }
} // namespace allergies
