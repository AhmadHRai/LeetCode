class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0], jump = questions[i][1];
            dp[i] = max(points + dp[min(jump + i + 1, n)], dp[i + 1]);
        }
        return dp[0];
    }
};