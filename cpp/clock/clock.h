#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent
{

    class clock
    {
    public:
        clock(int hour, int minute);
        static clock at(int hour, int minute);
        static clock helper(int hour, int minute);
        clock plus(int minutes);

        operator std::string() const;
        bool operator==(const clock &clock) const;
        bool operator!=(const clock &clock) const;

    private:
        void normalize();
        int hour_;
        int minute_;
    };

} // namespace date_independent

#endif // CLOCK_H