class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int prefix = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > prefix)
                res = max(res, nums[i] - prefix);
            else
                prefix = nums[i];
        }

        return res;
    }
};