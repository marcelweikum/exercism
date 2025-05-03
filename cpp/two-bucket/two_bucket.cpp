#include "two_bucket.h"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <set>
#include <utility>
#include <queue>
#include <tuple>
#include <vector>

namespace two_bucket
{

    measure_result measure(int bucket1_capacity, int bucket2_capacity,
                           int target_volume, bucket_id start_bucket)
    {
        if (target_volume > std::max(bucket1_capacity, bucket2_capacity) ||
            target_volume % std::gcd(bucket1_capacity, bucket2_capacity) != 0)
        {
            throw std::logic_error("Goal volume is not reachable");
        }

        int cap1 = bucket1_capacity;
        int cap2 = bucket2_capacity;
        bool startIsOne = (start_bucket == bucket_id::one);

        std::queue<std::tuple<int, int, int>> q;
        std::set<std::pair<int, int>> visited;

        int v1 = startIsOne ? cap1 : 0;
        int v2 = startIsOne ? 0 : cap2;
        q.emplace(v1, v2, 1);
        visited.insert({v1, v2});

        while (!q.empty())
        {
            auto [cur1, cur2, moves] = q.front();
            q.pop();

            if (cur1 == target_volume || cur2 == target_volume)
            {
                measure_result result;
                result.num_moves = moves;
                if (cur1 == target_volume)
                {
                    result.goal_bucket = bucket_id::one;
                    result.other_bucket_volume = cur2;
                }
                else
                {
                    result.goal_bucket = bucket_id::two;
                    result.other_bucket_volume = cur1;
                }
                return result;
            }

            std::vector<std::pair<int, int>> next_states;
            next_states.emplace_back(cap1, cur2);
            next_states.emplace_back(cur1, cap2);
            next_states.emplace_back(0, cur2);
            next_states.emplace_back(cur1, 0);
            int transfer = std::min(cur1, cap2 - cur2);
            next_states.emplace_back(cur1 - transfer, cur2 + transfer);
            transfer = std::min(cur2, cap1 - cur1);
            next_states.emplace_back(cur1 + transfer, cur2 - transfer);

            for (auto &ns : next_states)
            {
                if (!visited.insert(ns).second)
                    continue;

                if (startIsOne)
                {
                    if (ns.first == 0 && ns.second == cap2)
                        continue;
                }
                else
                {
                    if (ns.second == 0 && ns.first == cap1)
                        continue;
                }
                q.emplace(ns.first, ns.second, moves + 1);
            }
        }

        throw std::logic_error("Infinite loop detected");
    }

} // namespace two_bucket
