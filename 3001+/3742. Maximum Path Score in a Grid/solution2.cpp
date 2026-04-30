class Solution {
public:
    int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int K = std::min(k, m + n);
        int W = K + 1;
        std::vector<int> prev(n * W, -1), cur(n * W, -1);
        for (int i = 0; i < m; ++i) {
            std::fill(cur.begin(), cur.end(), -1);
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                int w = v > 0 ? 1 : 0;
                int* dst = &cur[j * W];
                if (i == 0 && j == 0) {
                    if (w <= K) dst[w] = v;
                    continue;
                }
                const int* up = i > 0 ? &prev[j * W] : nullptr;
                const int* left = j > 0 ? &cur[(j - 1) * W] : nullptr;
                for (int c = w; c <= K; ++c) {
                    int best = -1;
                    if (up && up[c - w] > best) best = up[c - w];
                    if (left && left[c - w] > best) best = left[c - w];
                    if (best >= 0) dst[c] = best + v;
                }
            }
            std::swap(prev, cur);
        }
        int ans = -1;
        const int* last = &prev[(n - 1) * W];
        for (int c = 0; c <= K; ++c) ans = std::max(ans, last[c]);
        return ans;
    }
};
