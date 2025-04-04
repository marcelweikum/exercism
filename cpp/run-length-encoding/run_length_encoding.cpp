#include "run_length_encoding.h"

namespace run_length_encoding
{

    std::string encode(std::string s)
    {
        std::string result{};
        int c_count{1};

        for (size_t i{}; i < s.size(); ++i)
        {
            if (s[i] == s[i + 1])
            {
                ++c_count;
            }
            else
            {
                if (c_count > 1)
                {
                    result += std::to_string(c_count);
                }
                result += s[i];
                c_count = 1;
            }
        }
        return result;
    }

    std::string decode(std::string s)
    {
        std::string result{};
        std::string c_count{};

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                c_count += s[i];
            }
            else
            {
                result += std::string(c_count.empty() ? 1 : std::stoi(c_count), s[i]);
                c_count.clear();
            }
        }
        return result;
    }

} // namespace run_length_encoding
