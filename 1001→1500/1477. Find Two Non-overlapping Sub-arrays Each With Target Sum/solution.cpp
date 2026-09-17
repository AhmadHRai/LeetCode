class Solution {
public:
    int minSumOfLengths(vector<int>& A, int k) {
        int n = A.size();
        int res = n + 1, sum = 0, i = 0;

        vector<int> dp(n + 1, n);

        for (int j = 0; j < n; j++) {
            sum += A[j];

            while (sum > k)
                sum -= A[i++];

            dp[j + 1] = dp[j];

            if (sum == k) {
                res = min(res, j - i + 1 + dp[i]);
                dp[j + 1] = min(dp[j], j - i + 1);
            }
        }

        return res == n + 1 ? -1 : res;
    }
};
