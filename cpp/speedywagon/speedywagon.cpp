#include "speedywagon.h"

namespace speedywagon
{

    // Enter your code below:

    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int> *data_array)
    {
        double avg{};
        for (auto element : *data_array)
        {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array)
        {
            if (element > avg)
                ++uv_index;
        }
        return uv_index;
    }

    bool connection_check(pillar_men_sensor *sensor)
    {
        return sensor != nullptr;
    }

    int activity_counter(speedywagon::pillar_men_sensor *arr_ptr, int size)
    {
        int sum{};
        for (int i{0}; i < size; i++)
        {
            sum += arr_ptr->activity;
            arr_ptr++;
        }
        return sum;
    }

    bool alarm_control(speedywagon::pillar_men_sensor *ptr)
    {
        if (ptr == nullptr)
        {
            return false;
        }

        if (ptr->activity > 0)
        {
            return true;
        }
        return false;
    }

    bool uv_alarm(speedywagon::pillar_men_sensor *ptr)
    {
        if (ptr == nullptr)
        {
            return false;
        }

        if (uv_light_heuristic(&(ptr->data)) > ptr->activity)
        {
            return true;
        }
        return false;
    }

} // namespace speedywagon
