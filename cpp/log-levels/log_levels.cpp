#include <string>

namespace log_line
{
    std::string message(std::string line)
    {
        std::string::size_type separator{line.find(" ")};
        return line.substr(separator + 1);
    }

    std::string log_level(std::string line)
    {
        std::string::size_type level_start{line.find("[") + 1};
        std::string::size_type level_end{line.find("]")};
        return line.substr(level_start, level_end - level_start);
    }

    std::string reformat(std::string line)
    {
        return log_line::message(line) + " (" + log_line::log_level(line) + ")";
    }
} // namespace log_line
