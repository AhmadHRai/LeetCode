class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long neg_cnt = 0, ans = 0, size = a.size(), minn = 1000000;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                ans += abs(a[i][j]);
                if (a[i][j] < 0)
                    neg_cnt++;
                minn = minn < abs(a[i][j]) ? minn : abs(a[i][j]);
            }
        if (neg_cnt % 2 == 0)
            return ans;
        else
            return ans - 2 * minn;
    }
};
