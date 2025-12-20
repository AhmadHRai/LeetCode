class Solution {
    bool isUnsorted(const vector<string>& strs, int j) {
        for (int i = 1; i < strs.size(); i++)
            if (strs[i][j] < strs[i - 1][j])
                return true;
        return false;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int j = 0; j < strs[0].size(); j++)
            res += isUnsorted(strs, j);
        return res;
    }
};
