class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        long long windowProfit = 0;
        long long sellHalfSum = 0;

        for (int i = 0; i < k; i++) {
            windowProfit += 1LL * strategy[i] * prices[i];
            if (i >= k / 2) {
                sellHalfSum += prices[i];
            }
        }

        long long bestGain = sellHalfSum - windowProfit;

        for (int l = 1; l + k - 1 < n; l++) {
            int r = l + k - 1;
            // slide windowProfit
            windowProfit -= 1LL * strategy[l - 1] * prices[l - 1];
            windowProfit += 1LL * strategy[r] * prices[r];

            // slide sellHalfSum
            sellHalfSum -= prices[l - 1 + k / 2];
            sellHalfSum += prices[r];
            bestGain = max(bestGain, sellHalfSum - windowProfit);
        }

        return baseProfit + max(0LL, bestGain);
    }
};
