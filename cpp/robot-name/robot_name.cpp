#include "robot_name.h"

#include <unordered_set>
#include <random>

namespace robot_name
{
    std::unordered_set<std::string> names;

    robot::robot()
    {
        name_ = generate_name();
    }

    std::string robot::name() const
    {
        return name_;
    }

    std::string robot::generate_name() const
    {
        static std::unordered_set<std::string> names;
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> letter_dist(0, 25);
        static std::uniform_int_distribution<> digit_dist(0, 9);

        std::string name;
        do
        {
            name.clear();
            name += 'A' + letter_dist(gen);
            name += 'A' + letter_dist(gen);
            name += '0' + digit_dist(gen);
            name += '0' + digit_dist(gen);
            name += '0' + digit_dist(gen);
        } while (!names.insert(name).second);

        return name;
    }

    void robot::reset()
    {
        name_ = generate_name();
    }

} // namespace robot_name