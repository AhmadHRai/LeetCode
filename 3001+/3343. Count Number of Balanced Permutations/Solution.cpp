class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
            /* Sum of the first i numbers */
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd);
                 oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                /* The number of bits that need to be filled in even numbered
                 * positions */
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target);
                     curr >= max(0, totSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt);
                         j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        /* The current digit is filled with j positions at odd
                         * positions, and cnt[i] - j positions at even positions
                         */
                        long long ways =
                            comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) %
                              MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return f[target][maxOdd];
    }
};