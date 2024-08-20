class Solution {
public:
    // Function to find the maximum number of stones a player can get in the Stone Game II
    int stoneGameII(vector<int>& piles) {
        // Get the number of piles
        int length = piles.size();
        // Initialize a DP table to store the maximum stones a player can collect
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
        // Initialize a suffix sum array to store cumulative sums from the end of piles
        vector<int> sufsum(length + 1, 0);
        
        // Fill the suffix sum array
        for (int i = length - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }
        
        // Set the DP table for the base case where only one player is left
        for (int i = 0; i <= length; i++) {
            dp[i][length] = sufsum[i];
        }
        
        // Fill the DP table
        for (int i = length - 1; i >= 0; i--) {
            for (int j = length - 1; j >= 1; j--) {
                // Try all possible moves from 1 to 2*j piles
                for (int X = 1; X <= 2 * j && i + X <= length; X++) {
                    // Update the DP value by maximizing the current choice
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
                }
            }
        }
        
        // Return the result for the initial state
        return dp[0][1];
    }
};

/*
Approach Summary:
- Use dynamic programming to determine the maximum number of stones a player can collect in the Stone Game II.
- Precompute the suffix sums of the piles to quickly get the sum of any subarray from index `i` to the end.
- Initialize the DP table with values where only one player is left.
- Update the DP table by considering all possible moves from 1 to 2 * current value of `j`.
- The result at dp[0][1] gives the maximum number of stones the first player can collect starting with `j=1`.

Time Complexity:
- O(n^3), where n is the number of piles. This is due to the triple nested loop structure.

Space Complexity:
- O(n^2), where n is the number of piles. This is used for the DP table and suffix sum array.
*/
