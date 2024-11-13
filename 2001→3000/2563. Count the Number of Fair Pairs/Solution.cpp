class Solution {
public:
    // Function to count fair pairs with sum between 'lower' and 'upper'
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the numbers first
        sort(nums.begin(), nums.end());

        // Return the count of pairs within the range [lower, upper]
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

private:
    // Helper function to count pairs less than a given value
    long long lower_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;

        // Two-pointer approach to find valid pairs
        while (left < right) {
            int sum = nums[left] + nums[right];

            // If sum is less than the target value, count all pairs between 'left' and 'right'
            // If sum is less than value, add the size of window to result and
            // move to the next index.
            if (sum < value) {
                result += (right - left);
                left++;  // Move the left pointer to the right
            } else {
                // Otherwise, shift the right pointer backwards, until we get a
                // valid window.
                right--;  // Move the right pointer to the left
            }
        }
        return result;
    }
};
