#include <vector>
#include <cstdint>
#include <algorithm>
#include <bit>

class Solution {
public:
    int maxPathScore(const std::vector<std::vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 2) {
            std::vector<int> dp(n, 0);
            for (int j = 1; j < n; ++j) dp[j] = dp[j - 1] + grid[0][j];
            for (int i = 1; i < m; ++i) {
                dp[0] += grid[i][0];
                for (int j = 1; j < n; ++j)
                    dp[j] = std::max(dp[j], dp[j - 1]) + grid[i][j];
            }
            return dp[n - 1];
        }

        // Count total 2s on the maximum possible path (upper bound for t)
        // A path has length m + n - 1, so t <= min(k, m + n - 2).
        const int K = k;
        const int WORDS = (K / 64) + 1;
        const uint64_t last_mask = (K % 64 == 63) ? ~0ULL : ((1ULL << ((K % 64) + 1)) - 1);

        // dp[j][t][w] -> bitmask of achievable costs `c` at col `j` with `t` twos
        // Using flat vector for cache efficiency; max_t grows dynamically per column
        std::vector<uint64_t> dp(n * (K + 1) * WORDS, 0ULL);
        std::vector<int> max_t(n, -1);

        auto idx = [&](int j, int t, int w) {
            return (j * (K + 1) + t) * WORDS + w;
        };

        auto shift_left_1 = [&](uint64_t* dst, const uint64_t* src) {
            uint64_t carry = 0;
            for (int w = 0; w < WORDS; ++w) {
                uint64_t val = src[w];
                dst[w] = (val << 1) | carry;
                carry = val >> 63;
            }
            dst[WORDS - 1] &= last_mask;
        };

        // Base case at (0, 0): cost = 0, twos = 0 -> bit 0 is set
        dp[idx(0, 0, 0)] = 1ULL;
        max_t[0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                int v = grid[i][j];
                int mt = max_t[j];
                if (j > 0) mt = std::max(mt, max_t[j - 1]);
                if (mt < 0) {
                    max_t[j] = -1;
                    continue;
                }

                // Combine Up (already in dp[j]) and Left (in dp[j-1])
                if (j > 0) {
                    for (int t = 0; t <= mt; ++t) {
                        uint64_t* u = &dp[idx(j, t, 0)];
                        const uint64_t* l = &dp[idx(j - 1, t, 0)];
                        for (int w = 0; w < WORDS; ++w) u[w] |= l[w];
                    }
                }

                if (v == 0) {
                    max_t[j] = mt; // Cost +0, Twos +0
                } else if (v == 1) {
                    // Cost +1 (left shift bitset by 1), Twos +0
                    int new_mt = -1;
                    for (int t = 0; t <= mt; ++t) {
                        uint64_t* u = &dp[idx(j, t, 0)];
                        shift_left_1(u, u);
                        for (int w = 0; w < WORDS; ++w) {
                            if (u[w]) { new_mt = t; break; }
                        }
                    }
                    max_t[j] = new_mt;
                } else {
                    // v == 2: Cost +1 (left shift by 1), Twos +1 (shift t -> t+1)
                    int limit = std::min(mt + 1, K);
                    int new_mt = -1;
                    for (int t = limit; t >= 1; --t) {
                        uint64_t* dst = &dp[idx(j, t, 0)];
                        const uint64_t* src = &dp[idx(j, t - 1, 0)];
                        shift_left_1(dst, src);
                        if (new_mt == -1) {
                            for (int w = 0; w < WORDS; ++w) {
                                if (dst[w]) { new_mt = t; break; }
                            }
                        }
                    }
                    std::fill_n(&dp[idx(j, 0, 0)], WORDS, 0ULL);
                    max_t[j] = new_mt;
                }
            }
        }

        // Extract max(c + t) from the bitsets at (m - 1, n - 1)
        int ans = -1;
        for (int t = 0; t <= max_t[n - 1]; ++t) {
            const uint64_t* u = &dp[idx(n - 1, t, 0)];
            for (int w = WORDS - 1; w >= 0; --w) {
                if (u[w]) {
                    int highest_bit = 63 - std::countl_zero(u[w]);
                    int max_c = w * 64 + highest_bit;
                    ans = std::max(ans, max_c + t);
                    break; // Only highest cost c matters for a fixed t!
                }
            }
        }
        return ans;
    }
};
