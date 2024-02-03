/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var maxSumAfterPartitioning = function(arr, k) {
    const n = arr.length;
    const dp = new Array(n + 1).fill(0);

    for (let i = 1; i <= n; i++) {
        let curMax = 0, curSum = 0;

        // Determine the maximum element within the current window
        for (let j = 1; j <= k && i - j >= 0; j++) {
            curMax = Math.max(curMax, arr[i - j]);
            curSum = Math.max(curSum, curMax * j + dp[i - j]);
        }

        // Update the dynamic programming table with the maximum sum at the current position
        dp[i] = curSum;
    }

    return dp[n];
};

/*
Approach
  Adopt a DP approach with a single-pass iteration over the array. We use a sliding window technique to determine the maximum element within the current window of size k.
  For each position i, we calculate the maximum sum by considering different partition sizes and update the dynamic programming table accordingly.

Complexity
    Time complexity: O(n * k)
        The outer loop runs for each element in the array (O(n)).
        The inner loop, which checks the maximum element within the current window, runs for a maximum of 'k' iterations.
        Overall time complexity is O(n * k).

    Space complexity: O(n)
        We use a dynamic programming table of size n + 1.
        Additional variables (curMax, curSum) require constant space.
        Overall space complexity is O(n).
*/
