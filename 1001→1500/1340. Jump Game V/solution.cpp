class Solution {
public:
    int dp[1001] = {};

    int dfs(vector<int>& arr, int i, int d, int res = 1) {
        if (dp[i])
            return dp[i];
        for (auto j = i + 1;
             j <= min(i + d, (int)arr.size() - 1) && arr[j] < arr[i]; ++j)
            res = max(res, 1 + dfs(arr, j, d));
        for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j)
            res = max(res, 1 + dfs(arr, j, d));
        return dp[i] = res;
    }

    int maxJumps(vector<int>& arr, int d, int res = 1) {
        for (auto i = 0; i < arr.size(); ++i)
            res = max(res, dfs(arr, i, d));
        return res;
    }
};
