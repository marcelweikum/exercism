#pragma once

#include <vector>
#include <cstddef>

namespace list_ops
{

    void append(std::vector<int> &f_list, std::vector<int> &s_list);

    template <typename T>
    auto concat(const std::vector<T> &list)
    {
        std::vector<typename T::value_type> result;

        for (const auto &sublist : list)
        {
            result.insert(result.end(), sublist.begin(), sublist.end());
        }

        return result;
    }

    template <typename T, typename Func>
    std::vector<T> filter(const std::vector<T> &input, Func predicate)
    {
        std::vector<T> result;
        for (const auto &el : input)
        {
            if (predicate(el))
            {
                result.push_back(el);
            }
        }
        return result;
    }

    size_t length(std::vector<int> list);

    template <typename T, typename Func>
    auto map(const std::vector<T> &input, Func func)
    {
        using ReturnType = decltype(func(input[0]));
        std::vector<ReturnType> result;
        result.reserve(input.size());

        for (const auto &el : input)
        {
            result.push_back(func(el));
        }

        return result;
    }

    template <typename T, typename Acc, typename Func>
    Acc foldl(const std::vector<T> &input, Acc init, Func func)
    {
        for (const auto &el : input)
        {
            init = func(init, el);
        }
        return init;
    }

    template <typename T, typename Acc, typename Func>
    Acc foldr(const std::vector<T> &input, Acc init, Func func)
    {
        for (auto it = input.rbegin(); it != input.rend(); ++it)
        {
            init = func(init, *it);
        }
        return init;
    }

    template <typename T>
    std::vector<T> reverse(const std::vector<T> &input)
    {
        std::vector<T> result(input.rbegin(), input.rend());
        return result;
    }

} // namespace list_ops
