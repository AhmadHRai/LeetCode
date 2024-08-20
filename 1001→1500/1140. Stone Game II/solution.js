/**
 * Function to calculate the maximum number of stones a player can collect in the Stone Game II
 * @param {number[]} piles - Array representing the number of stones in each pile
 * @return {number} - Maximum number of stones the player can collect
 */
var stoneGameII = function(piles) {
    const n = piles.length; // Get the number of piles
    const memo = Array.from(Array(n), () => Array(n).fill(0)); // Memoization table to store results of subproblems

    // Calculate prefix sums to quickly compute the sum of any subarray
    const prefixSum = [0];
    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + piles[i];
    }

    // Recursive function to calculate the maximum number of stones the player can collect
    const dfs = (start, M) => {
        if (start >= n) {
            return 0; // No stones left to collect if starting index is beyond the last pile
        }

        if (2 * M >= n - start) {
            return prefixSum[n] - prefixSum[start]; // If we can take all remaining piles
        }

        if (memo[start][M] !== 0) {
            return memo[start][M]; // Return already computed result for this state
        }

        let maxStones = 0; // Initialize the maximum stones that can be collected
        for (let i = 1; i <= 2 * M; i++) {
            const take = prefixSum[start + i] - prefixSum[start]; // Stones collected in this move
            const remaining = dfs(start + i, Math.max(i, M)); // Recursively calculate stones collected in the remaining piles
            maxStones = Math.max(maxStones, take + prefixSum[n] - prefixSum[start + i] - remaining);
        }

        memo[start][M] = maxStones; // Memoize the result
        return maxStones;
    };

    return dfs(0, 1); // Start the DFS from the beginning with initial M = 1
};

/*
Approach Summary:
- Use a dynamic programming approach with memoization to solve the problem.
- Compute prefix sums to enable quick calculation of the sum of any subarray.
- Define a recursive function `dfs` to explore all possible moves:
  - If all remaining piles can be taken in one move, return the sum of those piles.
  - Use memoization to store and reuse results of subproblems.
  - Calculate the maximum number of stones that can be collected by considering all possible moves and recursively calculating the result.

Time Complexity:
- O(n^2), where n is the number of piles. The recursion explores up to 2 * M choices at each state, and there are O(n^2) states to explore.

Space Complexity:
- O(n^2), for the memoization table and prefix sum array.
*/
