#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        int n = nums.size();
        // Since 1 <= nums[i] <= n <= 100, flat arrays on the stack are blazingly fast
        int last1[101];
        int last2[101];
        std::fill_n(last1, n + 1, -1);
        std::fill_n(last2, n + 1, -1);

        int min_span = n + 1;

        for (int k = 0; k < n; ++k) {
            int val = nums[k];

            // If we have seen this value at least twice before, we have 3 occurrences!
            if (last2[val] != -1) {
                min_span = std::min(min_span, k - last2[val]);
            }

            // Shift the history: second-to-last becomes last, last becomes current
            last2[val] = last1[val];
            last1[val] = k;
        }

        return min_span == n + 1 ? -1 : min_span * 2;
    }
};
