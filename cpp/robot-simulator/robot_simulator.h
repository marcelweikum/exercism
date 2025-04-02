#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <utility>
#include <string>

namespace robot_simulator
{

    enum Bearing
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    class Robot
    {
    public:
        Robot() : position_{0, 0}, bearing_{Bearing::NORTH} {}

        Robot(std::pair<int, int> position, Bearing bearing)
            : position_{position}, bearing_{bearing} {}

        std::pair<int, int> get_position() const;
        Bearing get_bearing() const;

        void turn_left();
        void turn_right();
        void advance();
        void execute_sequence(std::string sequence);

    private:
        std::pair<int, int> position_;
        Bearing bearing_;
    };

} // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H