#include "clock.h"

namespace date_independent
{
    clock::clock(int hour, int minute)
    {
        hour_ = hour;
        minute_ = minute;
        normalize();
    }

    clock clock::at(int hour, int minute)
    {
        return clock(hour, minute);
    }

    clock clock::plus(int minutes)
    {
        return clock(hour_, minute_ + minutes);
    }

    void clock::normalize()
    {
        hour_ += minute_ / 60;
        minute_ %= 60;

        if (minute_ < 0)
        {
            minute_ += 60;
            hour_ -= 1;
        }

        hour_ %= 24;
        if (hour_ < 0)
        {
            hour_ += 24;
        }
    }
    clock::operator std::string() const
    {
        std::string s_hour = (hour_ < 10 ? "0" : "") + std::to_string(hour_);
        std::string s_minute = (minute_ < 10 ? "0" : "") + std::to_string(minute_);
        return s_hour + ":" + s_minute;
    }

    bool clock::operator==(const clock &clock) const
    {
        return hour_ == clock.hour_ && minute_ == clock.minute_;
    }

    bool clock::operator!=(const clock &clock) const
    {
        return !(*this == clock);
    }
} // namespace date_independent
