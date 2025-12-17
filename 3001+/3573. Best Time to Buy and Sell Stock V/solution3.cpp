class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<long long> buy(k + 1, -1e9);
        vector<long long> sell(k + 1, 0);
        vector<long long> res(k + 1, 0);

        for (const auto& p : prices) {
            for (int i = 0; i < k; i++) {
                res[i] = max(max(res[i], buy[i + 1] + p), sell[i + 1] - p);
                buy[i + 1] = max(buy[i + 1], res[i + 1] - p);
                sell[i + 1] = max(sell[i + 1], res[i + 1] + p);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
