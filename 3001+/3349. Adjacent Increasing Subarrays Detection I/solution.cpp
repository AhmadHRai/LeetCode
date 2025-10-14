class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size(), up = 1, pre_max_up = 0, res = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            up++;
        } else {
            pre_max_up = up;
            up = 1;
        }
        res = max({res, up / 2, min(pre_max_up, up)});
    }
    return res >= k;
}
};