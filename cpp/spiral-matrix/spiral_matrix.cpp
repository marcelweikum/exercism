#include "spiral_matrix.h"

#include <utility>

namespace spiral_matrix
{

    std::vector<std::vector<uint32_t>> spiral_matrix(int n)
    {
        std::vector<std::vector<uint32_t>> spiral(n, std::vector<uint32_t>(n, 0));

        const std::pair<int, int> directions[4] = {
            {0, 1},  // right
            {1, 0},  // down
            {0, -1}, // left
            {-1, 0}  // up
        };

        int row = 0, col = 0;
        int dir_idx = 0;
        for (uint32_t i = 1; i <= static_cast<uint32_t>(n * n); ++i)
        {
            spiral[row][col] = i;

            int next_row = row + directions[dir_idx].first;
            int next_col = col + directions[dir_idx].second;

            if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || spiral[next_row][next_col] != 0)
            {
                dir_idx = (dir_idx + 1) % 4;
                next_row = row + directions[dir_idx].first;
                next_col = col + directions[dir_idx].second;
            }

            row = next_row;
            col = next_col;
        }

        return spiral;
    }

} // namespace spiral_matrix
