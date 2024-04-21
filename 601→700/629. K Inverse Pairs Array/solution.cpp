class Solution {
public:
    // This function returns the number of different arrays consisting of numbers from 1 to n
    // such that there are exactly k inverse pairs in the array
    // An inverse pair is a pair of integers [i, j] where 0 <= i < j < n and nums[i] > nums[j]
    int kInversePairs(int n, int k) {
        // Define a 2D array dp of size 2 by 1001, and initialize the first element to 1
        // dp[i][j] will store the number of arrays of size i with j inverse pairs
        // We only need two rows of the array, as dp[i][j] only depends on dp[i-1][j] and dp[i][j-1]
        int dp[2][1001] = { 1 };
        // Loop through the array sizes from 1 to n
        for (int N = 1; N <= n; ++N)
            // Loop through the inverse pairs from 0 to k
            for (int K = 0; K <= k; ++K) {
                // The number of arrays of size N with K inverse pairs is equal to
                // the number of arrays of size N-1 with K inverse pairs (by appending N to the end)
                // plus the number of arrays of size N with K-1 inverse pairs (by inserting N somewhere)
                // modulo a large prime number to avoid overflow
                dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
                // However, we need to subtract the number of arrays of size N-1 with K-N inverse pairs
                // because they will produce more than K inverse pairs when appending N to the end
                // For example, if N = 3 and K = 2, then [3, 1, 2] has 2 inverse pairs, but [1, 2, 3] has 0
                // So we need to subtract dp[N-1][K-N] from dp[N][K]
                // We add a large prime number before modulo to avoid negative values
                if (K >= N)
                    dp[N % 2][K] = (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
            }
        // Return the final answer, which is the number of arrays of size n with k inverse pairs
        return dp[n % 2][k];
    }
};

/* 
Approach:
    The approach is to use dynamic programming to find the number of different arrays with k inverse pairs. The idea is to define a 
    function dp(N, K) that returns the number of arrays of size N with K inverse pairs, and use a recurrence relation to compute it 
    based on the previous values. The base case is dp(0, 0) = 1, as there is one array of size 0 with 0 inverse pairs (the empty array). 
    
Complexity:
    The time complexity is O(n * k), as there are n * k possible states, and each state takes O(1) time to compute. 
    The space complexity is O(k), as we only need two rows of the array, which take O(k) space each.
 */