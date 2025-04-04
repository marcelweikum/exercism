#include "sublist.h"

#include <algorithm>

namespace sublist
{

    List_comparison sublist(std::vector<int> f, std::vector<int> s)
    {

        if (f == s)
            return List_comparison::equal;

        if (f.empty() || search(s.begin(), s.end(), f.begin(), f.end()) != s.end())
            return List_comparison::sublist;

        if (s.empty() || search(f.begin(), f.end(), s.begin(), s.end()) != f.end())
            return List_comparison::superlist;

        return List_comparison::unequal;
    }

} // namespace sublist
