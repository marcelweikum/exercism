#include "list_ops.h"

namespace list_ops
{

    void append(std::vector<int> &f_list, std::vector<int> &s_list)
    {
        for (int n : s_list)
        {
            f_list.push_back(n);
        }
    }

    size_t length(std::vector<int> list)
    {
        return list.size();
    }

} // namespace list_ops
