#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <vector>
#include <string>
#include <map>

namespace grade_school
{
    class school
    {
    public:
        std::map<int, std::vector<std::string>> roster() const;

        void add(std::string name, int grade);

        std::vector<std::string> grade(int grade) const;

    private:
        std::map<int, std::vector<std::string>> grade_{};
    };
} // namespace grade_school

#endif // GRADE_SCHOOL_H