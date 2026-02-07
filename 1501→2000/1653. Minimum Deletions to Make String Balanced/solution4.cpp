class Solution {
public:
    int minimumDeletions(string const& s) {
        int const n = s.size();
        int bs = 0, dp = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                bs++;
            } else {
                dp = min(dp + 1, bs);
            }
        }
        return dp;
    }
};
