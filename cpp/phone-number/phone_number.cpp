#include "phone_number.h"

#include <stdexcept>

namespace phone_number
{

    phone_number::phone_number(std::string number)
        : phone_number_{std::move(number)}
    {
        phone_number_ = this->number();
    }

    std::string phone_number::number()
    {
        std::string result{};

        for (size_t i{}; i < phone_number_.size(); ++i)
        {
            if (isdigit(phone_number_[i]))
                result += phone_number_[i];
        }

        if (result.size() > 10)
        {
            if (result[0] == '1')
            {
                result = std::string(result.begin() + 1, result.end());
            }
            else
            {
                throw std::domain_error("Invalid prefix");
            }
        }
        else if (result.size() < 10)
        {
            throw std::domain_error("Invalid length");
        }
        if (result[0] == '0' || result[0] == '1' || result[3] == '0' || result[3] == '1')
        {
            throw std::domain_error("Wrong N digit");
        }

        return result;
    }

} // namespace phone_number
