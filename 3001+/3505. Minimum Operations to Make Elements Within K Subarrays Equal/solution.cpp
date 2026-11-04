class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size(), odd = x & 1;
        multiset<int> s(nums.begin(), nums.begin() + x);
        auto mid = next(s.begin(), x / 2);
        long long low = accumulate(s.begin(), mid, 0LL);
        long long total = accumulate(s.begin(), s.end(), 0LL);

        vector<long long> cost(n - x + 1);
        cost[0] = total - 2 * low - odd * (*mid);

        for (int i = x; i < n; ++i) {
            int in = nums[i], out = nums[i - x];
            s.insert(in);
            if (in < *mid) low += in - *--mid;
            if (out < *mid) {
                low += *mid++ - out;
                s.erase(s.find(out));
            } else if (out == *mid) {
                mid = s.erase(mid);
            } else {
                s.erase(s.find(out));
            }
            total += in - out;
            cost[i - x + 1] = total - 2 * low - odd * (*mid);
        }

        vector<long long> dp(n + 1, 0);
        for (int j = 0; j < k; ++j) {
            vector<long long> next_dp(n + 1, LLONG_MAX / 2);
            for (int i = x; i <= n; ++i)
                next_dp[i] = min(next_dp[i - 1], dp[i - x] + cost[i - x]);
            dp = move(next_dp);
        }
        return dp[n];
    }
};
