class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long baseProfit = 0;
        long long windowProfit = 0;
        long long sellHalfSum = 0;

        // build baseProfit + first window
        for (int i = 0; i < n; i++) {
            long long val = 1LL * strategy[i] * prices[i];
            baseProfit += val;

            if (i < k) {
                windowProfit += val;
                if (i >= half) {
                    sellHalfSum += prices[i];
                }
            }
        }

        long long bestGain = sellHalfSum - windowProfit;

        // slide window
        for (int l = 1; l + k - 1 < n; l++) {
            int r = l + k - 1;

            windowProfit -= 1LL * strategy[l - 1] * prices[l - 1];
            windowProfit += 1LL * strategy[r] * prices[r];

            sellHalfSum -= prices[l - 1 + half];
            sellHalfSum += prices[r];

            bestGain = max(bestGain, sellHalfSum - windowProfit);
        }

        return baseProfit + max(0LL, bestGain);
    }
};
