class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size(), res = LLONG_MIN, psum = nums[0];
        for (int l = 0, p = 0, q = 0, r = 1; r < nums.size(); ++r) {
            psum += nums[r];
            if (nums[r - 1] == nums[r]) {
                l = r;
                psum = nums[r];
            } else if (nums[r - 1] > nums[r]) {
                if (r > 1 && nums[r - 2] < nums[r - 1]) { // flip
                    p = r - 1;
                    while (l < q)
                        psum -= nums[l++];
                    while (l + 1 < p && nums[l] < 0)
                        psum -= nums[l++];
                }
            } else {
                if (r > 1 && nums[r - 2] > nums[r - 1]) // flip
                    q = r - 1;
                if (l < p && p < q)
                    res = max(res, psum);
            }
        }
        return res;
    }
};
