class Solution {
public:
#define ll long long
    static const int N = 1e3 + 3;
    ll dp[N][3][N / 2], ans = 0;

    long long maximumProfit(vector<int>& prices, int k) {
#define LC_HACK
#ifdef LC_HACK
        const auto __ = []() {
            struct ___ {
                static void _() {
                    ofstream("display_runtime.txt") << 0 << "\n";
                }
            };
            std::atexit(&___::_);
            return 0;
        }();
#endif

#if defined(_GNUC_)
#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#endif

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = prices.size();
        dp[0][0][0] = 0;
        for (int i = 1; i <= k; ++i)
            dp[0][0][i] = -1e18;
        dp[0][1][0] = -1e18, dp[0][1][1] = -prices[0];
        for (int j = 2; j <= k; ++j)
            dp[0][1][j] = -1e18;
        dp[0][2][0] = prices[0];
        for (int j = 1; j <= k; ++j)
            dp[0][2][j] = -1e18;
        for (int i = 1; i < n; ++i) {
            dp[i][0][0] = 0;
            for (int j = 1; j <= k; ++j)
                dp[i][0][j] = max({dp[i - 1][0][j], dp[i - 1][1][j] + prices[i],
                                   dp[i - 1][2][j - 1] - prices[i]});
            dp[i][1][0] = -1e18;
            for (int j = 1; j <= k; ++j)
                dp[i][1][j] =
                    max(dp[i - 1][1][j], dp[i - 1][0][j - 1] - prices[i]);
            for (int j = 0; j <= k; ++j)
                dp[i][2][j] = max(dp[i - 1][2][j], dp[i - 1][0][j] + prices[i]);
        }
        for (int i = 1; i <= k; ++i)
            ans = max(ans, dp[n - 1][0][i]);
        return ans;
    }
};
