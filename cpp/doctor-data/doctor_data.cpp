// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

#include "doctor_data.h"
namespace heaven
{
    std::string get_older_bob(heaven::Vessel instance1, heaven::Vessel instance2)
    {
        if (instance1.generation < instance2.generation)
        {
            return instance1.name;
        }
        return instance2.name;
    }
    bool in_the_same_system(heaven::Vessel instance1, heaven::Vessel instance2)
    {
        if (instance1.current_system == instance2.current_system)
        {
            return true;
        }
        return false;
    }
}