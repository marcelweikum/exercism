#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent
{

    class clock
    {
    public:
        clock(int hour, int minute);
        static std::string at(int hour, int minute);

    private:
        int hour_;
        int minute_;
    };

} // namespace date_independent

#endif // CLOCK_H