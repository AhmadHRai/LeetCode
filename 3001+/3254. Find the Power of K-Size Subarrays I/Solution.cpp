class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // If k is 1, every single element is a valid subarray, so return the original array
        if (k == 1) {
            return nums;  // If k is 1, no modification is needed
        }

        size_t length = nums.size();  // Get the size of the input array
        vector<int> result(length - k + 1, -1);  // Initialize result array with -1, to store results of subarrays
        int consecutiveCount = 1;  // Initialize the consecutive count to 1 (since each element is trivially a consecutive sequence of length 1)

        // Iterate over the array to check consecutive numbers
        for (size_t index = 0; index < length - 1; index++) {
            // Check if the current element and the next one are consecutive
            if (nums[index] + 1 == nums[index + 1]) {
                consecutiveCount++;  // Increment the consecutive count if they are consecutive
            } else {
                consecutiveCount = 1;  // Reset the count if not consecutive
            }

            // If we have enough consecutive elements, update the result array
            if (consecutiveCount >= k) {
                result[index - k + 2] = nums[index + 1];  // Store the element that ends the valid subarray
            }
        }

        return result;  // Return the final results array
    }
};

/*
    Approach:
    - The problem requires finding all subarrays of length `k` where the subarray consists of consecutive integers.
    - The algorithm follows a linear scan approach where it tracks the count of consecutive elements in the array.
    - We initialize the `result` array with `-1` values, representing the default value for non-valid subarrays.
    - As we iterate through the array, we check if the current and next element are consecutive. If they are, we increment a counter (`consecutiveCount`).
    - Whenever the `consecutiveCount` becomes greater than or equal to `k`, it means we found a valid subarray of length `k` with consecutive numbers. We then update the `result` array at the appropriate index.
    - The `result` array stores the last element of each valid subarray of length `k` that contains consecutive integers.

    Time Complexity:
    - The algorithm iterates through the array once, performing constant-time operations for each element, making the time complexity `O(n)`, where `n` is the number of elements in `nums`.
    - Therefore, the overall time complexity is linear in terms of the input size.

    Space Complexity:
    - The space complexity is `O(n)`, where `n` is the size of the input array. This space is used to store the `result` array.
    - We only use a few additional variables (`length`, `consecutiveCount`, etc.) which require constant space.

    Edge Cases:
    - If `k == 1`, every element is trivially part of a valid subarray, so we return the array unchanged.
    - If no valid subarray is found, the result will contain all `-1` values.
*/
