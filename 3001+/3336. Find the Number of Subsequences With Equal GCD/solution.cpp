class Solution {
    static constexpr int MOD = 1000000007;
    static constexpr int LIM = 201;

    static inline int μ[LIM];
    static inline int lcms[LIM][LIM];
    static inline int pow2[LIM], pow3[LIM];

    static inline int init = [] {
        for (int i = 1; i < LIM; i++)
            for (int j = 1; j < LIM; j++)
                lcms[i][j] = ::lcm(i, j);

        pow2[0] = pow3[0] = 1;

        for (int i = 1; i < LIM; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
            pow3[i] = ((long long)pow3[i - 1] * 3) % MOD;
        }

        μ[1] = 1;
        for (int i = 1; i < LIM; i++)
            for (int j = i * 2; j < LIM; j += i)
                μ[j] -= μ[i];

        return false;
    }();

public:
    int subsequencePairCount(vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());

        vector<int> count(mx + 1);

        for (int n : nums)
            count[n]++;

        for (int i = 1; i <= mx; i++)
            for (int j = i * 2; j <= mx; j += i)
                count[i] += count[j];

        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));
        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j <= mx; j++) {
                int l = lcms[i][j];
                int c = 0;
                if (l <= mx) c = count[l];

                int ci = count[i];
                int cj = count[j];
                dp[i][j] = ((long long)pow3[c] * pow2[ci + cj - c * 2] - pow2[ci] - pow2[cj] + 1) % MOD;
            }
        }

        long long res = 0;

        for (int i = 1; i <= mx; i++)
            for (int j = 1; j <= mx / i; j++)
                for (int k = 1; k <= mx / i; k++)
                    res += (long long)μ[j] * μ[k] * dp[j * i][k * i];

        return (res % MOD + MOD) % MOD;
    }
};
