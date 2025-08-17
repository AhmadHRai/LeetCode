class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1);

        dp[0] = 1;

        double s = k > 0 ? 1 : 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = s / maxPts;
            if (i < k)
                s += dp[i];

            if (i - maxPts >= 0 && i - maxPts < k)
                s -= dp[i - maxPts];

            // for (int j = 1; j <= maxPts; j++) {
            //     if (i - j >= 0 && i - j < k) {
            //         dp[i] += dp[i - j] / maxPts;
            //     }
            // }
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};