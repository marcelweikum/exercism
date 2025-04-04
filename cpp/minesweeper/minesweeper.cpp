#include "minesweeper.h"

namespace minesweeper
{

    const std::vector<std::pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    std::vector<std::string> annotate(std::vector<std::string> board)
    {
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '*')
                    continue;

                int count{0};

                for (const auto &[dx, dy] : directions)
                {
                    int ni = static_cast<int>(i) + dx;
                    int nj = static_cast<int>(j) + dy;

                    if (ni >= 0 && ni < static_cast<int>(board.size()) && nj >= 0 && nj < static_cast<int>(board[0].size()))
                    {
                        if (board[ni][nj] == '*')
                            ++count;
                    }
                }

                board[i][j] = count > 0 ? '0' + count : ' ';
            }
        }

        return board;
    }

} // namespace minesweeper
