class Solution {
    int n;
    vector<vector<int>> dp;

public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        int dp[n + 1][3];
        dp[0][0] = 1;
        dp[0][1] = dp[0][2] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int m = 0; m < 3; ++m) {
                int skip = dp[i - 1][m];
                int pick = 0;
                int x = dp[i - 1][(m + nums[i - 1]) % 3];

                if (x)
                    pick = nums[i - 1] + x;

                dp[i][m] = max(pick, skip);
            }
        }
        return dp[n][0] - 1;
    }
};
