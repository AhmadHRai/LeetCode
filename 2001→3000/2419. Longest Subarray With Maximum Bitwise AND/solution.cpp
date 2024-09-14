class Solution {
public:
    // Method to find the length of the longest subarray consisting of the maximum value in `nums`
    int longestSubarray(vector<int>& nums) {
        // Initialize variables
        int maxVal = 0;          // To keep track of the current maximum value found in the array
        int ans = 0;            // To keep track of the length of the longest subarray with the maximum value
        int currentStreak = 0;  // To keep track of the current length of the subarray with the maximum value

        // Iterate through each number in the array
        for (int num : nums) {
            // If the current number is greater than the current maximum value
            if (maxVal < num) {
                // Update the maximum value
                maxVal = num;
                // Reset the length of the longest subarray and current streak since we have a new maximum value
                ans = currentStreak = 0;
            }

            // If the current number is equal to the maximum value
            if (maxVal == num) {
                // Increment the length of the current streak
                currentStreak++;
            } else {
                // If the number is not the maximum value, reset the current streak
                currentStreak = 0;
            }

            // Update the answer with the maximum of the current longest subarray length and the current streak
            ans = max(ans, currentStreak);
        }
        // Return the length of the longest subarray consisting of the maximum value
        return ans;
    }
};

/*
Approach:
1. Initialize variables to keep track of the maximum value encountered, the length of the longest subarray with the maximum value, and the current streak of the maximum value.
2. Iterate through each element in the input array:
   - If the current element is greater than the current maximum value, update the maximum value and reset the lengths of the longest subarray and current streak.
   - If the current element equals the maximum value, increment the length of the current streak.
   - If the current element is less than the maximum value, reset the current streak to 0.
3. Continuously update the length of the longest subarray with the maximum value based on the length of the current streak.
4. Return the length of the longest subarray with the maximum value after processing all elements.

Time Complexity:
- O(n), where `n` is the number of elements in the array. This is because we make a single pass through the array, performing constant-time operations for each element.

Space Complexity:
- O(1), as we are using only a fixed amount of extra space for the variables (`maxVal`, `ans`, `currentStreak`) and not using any additional data structures that grow with the input size.
*/
