class Solution {
    static inline int freq[100005];
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        int n = A.size();
        for (auto& x : A)
            freq[min(x, n)]++;

        int res = 1;
        for (int i = 2; i <= n; i++)
            res = min(res + freq[i], i);

        for (int i = 0; i <= n; i++)
            freq[i] = 0;

        return res;
    }
};
