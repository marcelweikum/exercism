#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <vector>
#include <string>
#include <unordered_set>

namespace allergies
{

    class allergy_test
    {
    public:
        allergy_test(int i);

        bool is_allergic_to(std::string);

        std::unordered_set<std::string> get_allergies();

    private:
        std::unordered_set<std::string> allergies_;
    };
} // namespace allergies

#endif // ALLERGIES_H