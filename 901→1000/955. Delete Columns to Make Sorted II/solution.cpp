class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].length(), i, j;
        vector<bool> sorted(n - 1, false);
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n - 1; ++i) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i < n - 1) continue;
            for (i = 0; i < n - 1; ++i) {
                sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
            }
        }
        return res;
    }
};
