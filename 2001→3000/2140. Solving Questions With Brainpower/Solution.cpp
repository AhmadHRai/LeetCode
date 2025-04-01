class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        return dfs(questions, 0, dp);
    }
    long long dfs(vector<vector<int>>& Q, int i, vector<long long>& dp) {
        if (i >= Q.size())
            return 0;
        if (dp[i] > 0)
            return dp[i];
        int points = Q[i][0], jump = Q[i][1];
        return dp[i] =
                   max(dfs(Q, i + 1, dp), points + dfs(Q, i + jump + 1, dp));
    }
};