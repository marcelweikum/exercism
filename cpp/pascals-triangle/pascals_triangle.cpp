#include "pascals_triangle.h"

namespace pascals_triangle
{

    std::vector<std::vector<int>> generate_rows(int rows)
    {
        std::vector<std::vector<int>> result{};
        std::vector<int> sub_result{};
        for (int i{}; i < rows; ++i)
        {
            for (int j{}; j < i + 1; ++j)
            {
                if (sub_result.empty() || j == i)
                {
                    sub_result.push_back(1);
                }
                else
                {
                    sub_result.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(sub_result);
            sub_result.clear();
        }
        return result;
    }

} // namespace pascals_triangle
