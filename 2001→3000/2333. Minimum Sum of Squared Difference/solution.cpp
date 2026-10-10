class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k) {
            return 0;
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        nums1.push_back(0);
        for (int i = 1; i <= n; i++) {
            long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
            if (cost > k) {
                long long q = k / i, r = k % i;
                long long hi = nums1[i - 1] - q;
                long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
                for (int j = i; j < n; j++) {
                    ans += (long long)nums1[j] * nums1[j];
                }
                return ans;
            }
            k -= cost;
        }
        return 0;
    }
};
