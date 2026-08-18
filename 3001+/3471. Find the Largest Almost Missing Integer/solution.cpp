class Solution {
public:
    int largestInteger(vector<int>& A, int k) {
        int f[51] = {0};
        for (auto& x : A)
            f[x]++;

        int res = -1, n = A.size();
        for (int i = 0; i < n; i++)
            if (k == n || (f[A[i]]==1 && (k==1||!i||i==n-1)))
                res = max(res, A[i]);

        return res;
    }
};
