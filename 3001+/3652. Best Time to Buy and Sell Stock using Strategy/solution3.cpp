const int N = 1e5 + 1;
long long sum[N];
class Solution {
public:
    static long long maxProfit(vector<int>& prices, vector<int>& strategy,
                               int k) {
        const int n = prices.size(), k2 = k / 2;
        memset(sum, 0, sizeof(long long) * (n + 1));
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + 1LL * strategy[i] * prices[i];
        }

        long long modify =
            reduce(prices.begin() + k / 2, prices.begin() + k, 0LL);
        long long profit = max(sum[n], modify + sum[n] - sum[k]);

        for (int i = 1; i + k <= n; i++) {
            modify += prices[i + k - 1] - prices[i + k2 - 1];
            profit = max(profit, modify + sum[n] - sum[i + k] + sum[i]);
        }
        return profit;
    }
};
