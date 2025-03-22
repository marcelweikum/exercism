#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores)
{
    std::vector<int> rounded_scores;
    for (double score : student_scores)
    {
        score = static_cast<int>(score);
        rounded_scores.push_back(score);
    }
    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores)
{
    int failed_students{0};
    for (int score : student_scores)
    {
        if (score <= 40)
        {
            failed_students++;
        }
    }
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score)
{
    std::array<int, 4> grade_thresholds;
    int total_range = highest_score - 40;
    int range = total_range / 4;
    for (int i{0}; i < 4; i++)
    {
        grade_thresholds[i] = 41 + (range * i);
    }
    return grade_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names)
{
    std::vector<std::string> student_ranking;
    for (int i{0}; i < student_scores.size(); i++)
    {
        student_ranking.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return student_ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names)
{
    for (int i{0}; i < student_scores.size(); i++)
    {
        if (student_scores[i] == 100)
        {
            return student_names[i];
        }
    }
    return "";
}
