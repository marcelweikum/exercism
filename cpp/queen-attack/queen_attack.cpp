#include "queen_attack.h"

#include <stdlib.h>

namespace queen_attack
{
    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    {
        auto is_valid_position = [](const std::pair<int, int> &pos)
        {
            return pos.first >= 0 && pos.first <= 7 && pos.second >= 0 && pos.second <= 7;
        };

        if (!is_valid_position(white) || !is_valid_position(black))
        {
            throw std::domain_error("invalid position");
        }
        if (white == black)
        {
            throw std::domain_error("invalid position");
        }

        white_ = white;
        black_ = black;
    }

    bool chess_board::can_attack() const
    {
        int dx = white_.first - black_.first;
        int dy = white_.second - black_.second;

        return white_.first == black_.first ||
               white_.second == black_.second ||
               std::abs(dx) == std::abs(dy);
    }

    std::pair<int, int> chess_board::white() const
    {
        return this->white_;
    }

    std::pair<int, int> chess_board::black() const
    {
        return this->black_;
    }
} // namespace queen_attack
