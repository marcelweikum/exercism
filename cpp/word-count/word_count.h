#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <vector>
#include <string>
#include <map>

namespace word_count
{

    std::map<std::string, int> words(std::string word_list);
    std::vector<std::string> get_words(std::string words);

} // namespace word_count

#endif // WORD_COUNT_H