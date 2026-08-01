class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // dp[i][j] represents the maximum score the current player can achieve
        // from the subarray nums[i...j].
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Base case: when the subarray has only one element, the player takes
        // that element.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill the DP table from bottom to top, left to right.
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start + 1; end < n; ++end) {

                // Option 1: Player picks nums[start].
                // The opponent will then play optimally to minimize the
                // remaining score for this player.
                long long pickStart =
                    nums[start] +
                    min((start + 2 <= end)
                            ? dp[start + 2][end]
                            : 0, // Opponent leaves start+2 to end
                        (start + 1 <= end - 1)
                            ? dp[start + 1][end - 1]
                            : 0 // Opponent leaves start+1 to end-1
                    );

                // Option 2: Player picks nums[end].
                // The opponent will similarly minimize the remaining score.
                long long pickEnd =
                    nums[end] + min((start + 1 <= end - 1)
                                        ? dp[start + 1][end - 1]
                                        : 0, // Opponent leaves start+1 to end-1
                                    (start <= end - 2)
                                        ? dp[start][end - 2]
                                        : 0 // Opponent leaves start to end-2
                                );

                // The current player chooses the option that maximizes their
                // total score.
                dp[start][end] = max(pickStart, pickEnd);
            }
        }

        long long player1Score = dp[0][n - 1];
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

        // Player 1 wins if their score is greater than or equal to Player 2's
        // score. Equivalently: 2 * player1Score >= totalSum
        return 2 * player1Score >= totalSum;
    }
};
