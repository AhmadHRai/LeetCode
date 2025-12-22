#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int N = strs.size();
        int W = strs[0].size();

        vector<vector<bool>> ok(W, vector<bool>(W, true));

        for (int i = 0; i < W; ++i) {
            for (int j = i + 1; j < W; ++j) {
                for (int r = 0; r < N; ++r) {
                    if (strs[r][i] > strs[r][j]) {
                        ok[i][j] = false;
                        break;
                    }
                }
            }
        }

        vector<int> dp(W, 1);
        for (int i = W - 2; i >= 0; --i) {
            for (int j = i + 1; j < W; ++j) {
                if (ok[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int kept = *max_element(dp.begin(), dp.end());
        return W - kept;
    }
};
