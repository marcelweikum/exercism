#include "meetup.h"

#include <stdexcept>

namespace meetup
{

    scheduler::scheduler(boost::gregorian::months_of_year month, int year)
    {
        this->month_ = month;
        this->year_ = year;
    }

    boost::gregorian::date scheduler::teenth(boost::date_time::weekdays weekday) const
    {
        for (int day = 13; day <= 19; ++day)
        {
            boost::gregorian::date d(year_, month_, day);
            if (d.day_of_week() == weekday)
            {
                return d;
            }
        }

        throw std::invalid_argument("No teenth weekday found");
    }

    boost::gregorian::date scheduler::monteenth() const { return teenth(boost::date_time::Monday); }
    boost::gregorian::date scheduler::tuesteenth() const { return teenth(boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::wednesteenth() const { return teenth(boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::thursteenth() const { return teenth(boost::date_time::Thursday); }
    boost::gregorian::date scheduler::friteenth() const { return teenth(boost::date_time::Friday); }
    boost::gregorian::date scheduler::saturteenth() const { return teenth(boost::date_time::Saturday); }
    boost::gregorian::date scheduler::sunteenth() const { return teenth(boost::date_time::Sunday); }

    boost::gregorian::date scheduler::nth(int number, boost::date_time::weekdays weekday) const
    {
        int count{};

        for (int day = 1; day <= 31; ++day)
        {
            boost::gregorian::date d(year_, month_, day);
            if (d.day_of_week() == weekday)
            {
                ++count;
                if (count == number)

                {
                    return d;
                }
            }
        }
        throw std::invalid_argument("No teenth weekday found");
    }

    boost::gregorian::date scheduler::first_monday() const { return nth(1, boost::date_time::Monday); }
    boost::gregorian::date scheduler::first_tuesday() const { return nth(1, boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::first_wednesday() const { return nth(1, boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::first_thursday() const { return nth(1, boost::date_time::Thursday); }
    boost::gregorian::date scheduler::first_friday() const { return nth(1, boost::date_time::Friday); }
    boost::gregorian::date scheduler::first_saturday() const { return nth(1, boost::date_time::Saturday); }
    boost::gregorian::date scheduler::first_sunday() const { return nth(1, boost::date_time::Sunday); }
    boost::gregorian::date scheduler::second_monday() const { return nth(2, boost::date_time::Monday); }
    boost::gregorian::date scheduler::second_tuesday() const { return nth(2, boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::second_wednesday() const { return nth(2, boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::second_thursday() const { return nth(2, boost::date_time::Thursday); }
    boost::gregorian::date scheduler::second_friday() const { return nth(2, boost::date_time::Friday); }
    boost::gregorian::date scheduler::second_saturday() const { return nth(2, boost::date_time::Saturday); }
    boost::gregorian::date scheduler::second_sunday() const { return nth(2, boost::date_time::Sunday); }
    boost::gregorian::date scheduler::third_monday() const { return nth(3, boost::date_time::Monday); }
    boost::gregorian::date scheduler::third_tuesday() const { return nth(3, boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::third_wednesday() const { return nth(3, boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::third_thursday() const { return nth(3, boost::date_time::Thursday); }
    boost::gregorian::date scheduler::third_friday() const { return nth(3, boost::date_time::Friday); }
    boost::gregorian::date scheduler::third_saturday() const { return nth(3, boost::date_time::Saturday); }
    boost::gregorian::date scheduler::third_sunday() const { return nth(3, boost::date_time::Sunday); }
    boost::gregorian::date scheduler::fourth_monday() const { return nth(4, boost::date_time::Monday); }
    boost::gregorian::date scheduler::fourth_tuesday() const { return nth(4, boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::fourth_wednesday() const { return nth(4, boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::fourth_thursday() const { return nth(4, boost::date_time::Thursday); }
    boost::gregorian::date scheduler::fourth_friday() const { return nth(4, boost::date_time::Friday); }
    boost::gregorian::date scheduler::fourth_saturday() const { return nth(4, boost::date_time::Saturday); }
    boost::gregorian::date scheduler::fourth_sunday() const { return nth(4, boost::date_time::Sunday); }

    boost::gregorian::date scheduler::last(boost::date_time::weekdays weekday) const
    {
        for (int day = boost::gregorian::gregorian_calendar::end_of_month_day(year_, month_); day >= 1; --day)
        {
            boost::gregorian::date d(year_, month_, day);
            if (d.day_of_week() == weekday)
            {
                return d;
            }
        }

        throw std::invalid_argument("No teenth weekday found");
    }

    boost::gregorian::date scheduler::last_monday() const { return last(boost::date_time::Monday); }
    boost::gregorian::date scheduler::last_tuesday() const { return last(boost::date_time::Tuesday); }
    boost::gregorian::date scheduler::last_wednesday() const { return last(boost::date_time::Wednesday); }
    boost::gregorian::date scheduler::last_thursday() const { return last(boost::date_time::Thursday); }
    boost::gregorian::date scheduler::last_friday() const { return last(boost::date_time::Friday); }
    boost::gregorian::date scheduler::last_saturday() const { return last(boost::date_time::Saturday); }
    boost::gregorian::date scheduler::last_sunday() const { return last(boost::date_time::Sunday); }
} // namespace meetup
