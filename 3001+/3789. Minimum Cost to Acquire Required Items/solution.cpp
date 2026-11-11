#include <algorithm>

class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long common = std::min(need1, need2);

        return common * std::min(cost1 + cost2, costBoth) +
               (need1 - common) * std::min(cost1, costBoth) +
               (need2 - common) * std::min(cost2, costBoth);
    }
};
