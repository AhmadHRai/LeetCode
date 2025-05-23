class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long maxSum =
            0; // Sum of max values per node (either toggled or not)
        int toggleParity =
            0; // Tracks parity of toggled nodes count (0 = even, 1 = odd)
        long long minDifference = 1LL
                                  << 60; // Minimum absolute difference between
                                         // toggled and untoggled values

        for (auto& value : nums) {
            long long toggledValue = value ^ k;
            maxSum += max((long long)value, toggledValue);

            // If toggling increases value, flip parity (toggle count)
            if (value < toggledValue) {
                toggleParity = 1 - toggleParity; // Flip parity bit
            }

            // Track minimum difference to fix parity if needed
            minDifference =
                min(minDifference, abs((long long)value - toggledValue));
        }

        // If toggled count is odd, subtract minDifference to fix parity (make
        // toggled count even)
        if (toggleParity == 1) {
            maxSum -= minDifference;
        }

        return maxSum;
    }
};