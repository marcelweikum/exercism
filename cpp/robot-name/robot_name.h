#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>

namespace robot_name
{

    class robot
    {
    public:
        robot();
        std::string name() const;
        void reset();

    private:
        std::string name_;
        std::string generate_name() const;
    };

} // namespace robot_name

#endif // ROBOT_NAME_H