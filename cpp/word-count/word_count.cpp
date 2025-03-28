#include "word_count.h"

namespace word_count
{

    std::map<std::string, int> words(std::string word_list)
    {
        std::map<std::string, int> map{};
        for (std::string word : get_words(word_list))
        {
            map[word] += 1;
        }
        return map;
    }

    std::vector<std::string> get_words(std::string words)
    {
        std::vector<std::string> vec{};
        size_t pointer{};
        bool is_break{false};

        for (size_t i = 0; i < words.size(); ++i)
        {
            words[i] = tolower(words[i]);

            if (!is_break)
            {
                if (!isalnum(words[i]) && (words[i] != '\'' || i == 0 || i + 1 == words.size() ||
                                           !isalnum(words[i - 1]) || !isalnum(words[i + 1])))
                {
                    is_break = true;
                    if (i > pointer)
                    {
                        vec.push_back(words.substr(pointer, i - pointer));
                    }
                }
            }
            else
            {
                if (isalnum(words[i]) || (words[i] == '\'' && i > 0 && i + 1 < words.size() &&
                                          isalnum(words[i - 1]) && isalnum(words[i + 1])))
                {
                    is_break = false;
                    pointer = i;
                }
            }
        }

        if (!is_break && pointer < words.size())
        {
            vec.push_back(words.substr(pointer));
        }

        return vec;
    }

} // namespace word_count
