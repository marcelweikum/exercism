#include "robot_simulator.h"

namespace robot_simulator
{

    std::pair<int, int> Robot::get_position() const
    {
        return position_;
    }

    Bearing Robot::get_bearing() const
    {
        return bearing_;
    }

    void Robot::turn_left()
    {
        bearing_ = static_cast<Bearing>((static_cast<int>(bearing_) + 3) % 4);
    }
    void Robot::turn_right()
    {
        bearing_ = static_cast<Bearing>((static_cast<int>(bearing_) + 1) % 4);
    }
    void Robot::advance()
    {
        switch (bearing_)
        {
        case Bearing::NORTH:
            position_.second += 1;
            break;
        case Bearing::EAST:
            position_.first += 1;
            break;
        case Bearing::SOUTH:
            position_.second -= 1;
            break;
        case Bearing::WEST:
            position_.first -= 1;
            break;
        default:
            break;
        }
    }
    void Robot::execute_sequence(std::string sequence)
    {
        for (char c : sequence)
        {
            switch (c)
            {
            case 'R':
                turn_right();
                break;
            case 'L':
                turn_left();
                break;
            case 'A':
                advance();
                break;
            default:
                break;
            }
        }
    }

} // namespace robot_simulator
