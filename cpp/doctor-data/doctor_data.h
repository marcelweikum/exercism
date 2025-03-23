// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include <string>

namespace star_map
{
    enum class System
    {
        BetaHydri,
        EpsilonEridani,
        Sol,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven
{
    class Vessel
    {
    public:
        Vessel(std::string name, int generation)
        {
            this->name = name;
            this->generation = generation;
        }
        Vessel(std::string name, int generation, star_map::System star_map)
        {
            this->name = name;
            this->generation = generation;
            this->current_system = star_map;
        }

        Vessel replicate(std::string name)
        {
            return Vessel(name, 2, this->current_system);
        }

        void make_buster()
        {
            this->busters++;
        }

        bool shoot_buster()
        {
            if (this->busters > 0)
            {
                --this->busters;
                return true;
            }
            return false;
        }

        std::string name{};
        int generation{};
        star_map::System current_system{star_map::System::Sol};
        int busters{};
    };
    std::string get_older_bob(heaven::Vessel instance1, heaven::Vessel instance2);

    bool in_the_same_system(heaven::Vessel instance1, heaven::Vessel instance2);
}