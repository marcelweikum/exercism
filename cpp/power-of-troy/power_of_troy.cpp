#include "power_of_troy.h"

namespace troy
{
    void give_new_artifact(human &human, std::string artifact_name)
    {
        human.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact> &possession1, std::unique_ptr<artifact> &possession2)
    {
        // std::unique_ptr<artifact> temp = std::move(possession1);
        // possession1 = std::move(possession2);
        // possession2 = std::move(temp);

        std::swap(possession1, possession2);
    }

    void manifest_power(human &human, std::string power_name)
    {
        human.own_power = std::make_unique<power>(power_name);
    }

    void use_power(human &caster, human &target)
    {
        target.influenced_by = caster.own_power;
    }

    int power_intensity(human &human)
    {
        return human.own_power.use_count();
    }

} // namespace troy
