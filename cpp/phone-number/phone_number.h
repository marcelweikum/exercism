#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number
{

    class phone_number
    {
    public:
        phone_number(std::string number);
        std::string number();

    private:
        std::string phone_number_;
    };

} // namespace phone_number

#endif // PHONE_NUMBER_H