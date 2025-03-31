#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <unordered_set>

namespace anagram
{

    class anagram
    {
    public:
        anagram(std::string word);
        std::unordered_set<std::string> matches(std::unordered_set<std::string> list);

    private:
        std::string word_;
        std::string sorted_word_;
    };

} // namespace anagram

#endif // ANAGRAM_H