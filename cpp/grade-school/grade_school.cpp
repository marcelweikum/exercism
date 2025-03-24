#include "grade_school.h"

#include <algorithm>

namespace grade_school
{
    std::map<int, std::vector<std::string>> school::roster() const
    {
        return grade_;
    }

    void school::add(std::string name, int grade)
    {
        grade_[grade].push_back(name);
        std::sort(grade_[grade].begin(), grade_[grade].end());
    }

    std::vector<std::string> school::grade(int grade) const
    {
        if (grade_.count(grade) > 0)
        {
            return grade_.at(grade);
        }
        return std::vector<std::string>{};
    }
} // namespace grade_school
