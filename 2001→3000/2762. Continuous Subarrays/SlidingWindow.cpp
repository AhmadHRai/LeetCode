class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int right = 0, left = 0;
        int curMin, curMax;
        long long windowLen = 0, total = 0;

        // Initialize window with the first element
        curMin = curMax = nums[right];

        for (right = 0; right < nums.size(); right++) {
            // Update min and max for the current window
            curMin = min(curMin, nums[right]);
            curMax = max(curMax, nums[right]);

            // If window condition breaks (diff > 2)
            if (curMax - curMin > 2) {
                // Add subarrays from the previous valid window
                windowLen = right - left;
                total += (windowLen * (windowLen + 1) / 2);

                // Start a new window at the current position
                left = right;
                curMin = curMax = nums[right];

                // Expand left boundary while maintaining the condition
                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    curMin = min(curMin, nums[left]);
                    curMax = max(curMax, nums[left]);
                }

                // Remove overcounted subarrays if left boundary expanded
                if (left < right) {
                    windowLen = right - left;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }

        // Add subarrays from the final window
        windowLen = right - left;
        total += (windowLen * (windowLen + 1) / 2);

        return total;
    }
};

/* 
Approach:
    Use a sliding window approach with two pointers, left and right, to maintain a valid window. The window is expanded as long as the difference
    between the maximum and minimum values of the current subarray is less than or equal to 2. If the condition is violated, the left pointer is 
    adjusted to shrink the window until it becomes valid again.

Complexity:
    Time Complexity: O(n), where n is the length of the input array. Both the left and right pointers traverse the array at most once, and for each position, the operations inside the loop take constant time.

    Space Complexity: O(1), since the solution uses only a few extra variables (curMin, curMax, windowLen, and total) and does not require any additional data structures that scale with the size of the input.
*/