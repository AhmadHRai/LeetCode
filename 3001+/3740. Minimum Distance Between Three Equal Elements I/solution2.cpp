#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        int n = nums.size();
        int min_span = n + 1;

        for (int k = 0; k < n; ++k) {
            // Extract original value (lowest 7 bits)
            int val = (nums[k] & 127) - 1;

            // Unpack last1 and last2 stored at nums[val]
            int state = nums[val];
            int last1 = (state >> 7) & 127;  // 0 means not seen, otherwise index + 1
            int last2 = (state >> 14) & 127; // 0 means not seen, otherwise index + 1

            if (last2 > 0) {
                min_span = std::min(min_span, k - (last2 - 1));
            }

            // Pack the updated history back into nums[val]:
            // Clear bits 7..20, then set new last1 = k + 1 and new last2 = old last1
            nums[val] = (state & 127) | ((k + 1) << 7) | (last1 << 14);
        }

        return min_span == n + 1 ? -1 : min_span * 2;
    }
};
