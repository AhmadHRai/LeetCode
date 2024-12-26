// target_sum_ways_dp.cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array
        vector<int> dp(2 * totalSum + 1, 0); // Initialize the DP table for possible sums

        // Initialize the first row of the DP table
        dp[nums[0] + totalSum] = 1;     // Adding nums[0]
        dp[-nums[0] + totalSum] += 1;   // Subtracting nums[0]

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            vector<int> next(2 * totalSum + 1, 0); // Temporary table for current state
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) { // Check if the current sum is valid
                    // Update the next state for adding and subtracting nums[index]
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next; // Move to the next state
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};

/*
- Intuition:
    The problem can be thought of as finding the number of ways to partition the array into two subsets such that the difference between their sums equals the target. 
    Dynamic Programming (DP) is used to efficiently compute the number of ways to achieve various sums using the elements of the array.

- Algorithm:
    1. Calculate the total sum of the array (`totalSum`). This helps define the range of possible sums.
    2. Use a DP table where `dp[sum + totalSum]` represents the number of ways to achieve a sum `sum` using the first few elements of the array:
        - Initialize the DP table for the first element of the array.
        - For each subsequent element in the array, update the DP table by considering both adding and subtracting the element for all previously achievable sums.
    3. At the end of processing all elements, return `dp[target + totalSum]` if the target is within the valid range; otherwise, return 0.

- Complexity:
    Time Complexity: O(n * totalSum)
        - The outer loop runs for each element of the array (`n`), and the inner loop iterates over the range of possible sums (`2 * totalSum`).
    Space Complexity: O(totalSum)
        - The space required is proportional to the range of possible sums (`2 * totalSum`) as the DP table is reused.
*/
