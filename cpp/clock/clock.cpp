#include "clock.h"

namespace date_independent
{
    clock::clock(int hour, int minute)
    {
        hour_ = hour;
        minute_ = minute;
    }

    std::string clock::at(int hour, int minute)
    {
        std::string s_hour{};
        std::string s_minute{};
        while ((hour >= 24 || hour < 0) || (minute >= 60 || minute < 0))
        {
            if (hour >= 24)
            {
                hour -= 24;
            }
            else if (hour < 0)
            {
                hour += 24;
            }

            if (minute >= 60)
            {
                minute -= 60;
                hour += 1;
            }
            else if (minute < 0)
            {
                minute += 60;
                hour -= 1;
            }
        }

        if (hour < 10)
        {
            s_hour = '0' + std::to_string(hour);
        }
        else
        {
            s_hour = std::to_string(hour);
        }
        if (minute < 10)
        {
            s_minute = '0' + std::to_string(minute);
        }
        else
        {
            s_minute = std::to_string(minute);
        }
        return s_hour + ':' + s_minute;
    }

} // namespace date_independent
