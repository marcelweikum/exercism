#include "parallel_letter_frequency.h"

#include <thread>
#include <mutex>
#include <cctype>
#include <unordered_map>
#include <algorithm>
#include <vector>

namespace parallel_letter_frequency
{

    const size_t MAX_THREADS = std::thread::hardware_concurrency();
    std::mutex freq_mutex;

    void count_frequencies(const std::vector<std::string_view> &texts,
                           std::unordered_map<char, int> &freq_map)
    {
        std::unordered_map<char, int> local_freq_map;

        for (const auto &text : texts)
        {
            for (char ch : text)
            {
                if (std::isalpha(ch))
                {
                    char lower = std::tolower(ch);
                    local_freq_map[lower]++;
                }
            }
        }

        std::lock_guard<std::mutex> lock(freq_mutex);
        for (const auto &[letter, count] : local_freq_map)
        {
            freq_map[letter] += count;
        }
    }

    std::unordered_map<char, int> frequency(const std::vector<std::string_view> &texts)
    {
        std::unordered_map<char, int> freq_map;

        if (texts.empty())
        {
            return freq_map;
        }

        size_t num_threads = std::min(MAX_THREADS, texts.size());
        size_t chunk_size = texts.size() / num_threads;

        std::vector<std::thread> threads;
        std::vector<std::vector<std::string_view>> chunks(num_threads);

        for (size_t i = 0; i < num_threads; ++i)
        {
            auto start = texts.begin() + i * chunk_size;
            auto end = (i == num_threads - 1) ? texts.end() : start + chunk_size;

            chunks[i] = std::vector<std::string_view>(start, end);
        }

        for (size_t i = 0; i < num_threads; ++i)
        {
            threads.emplace_back(count_frequencies, std::ref(chunks[i]), std::ref(freq_map));
        }

        for (auto &t : threads)
        {
            t.join();
        }

        return freq_map;
    }

}
