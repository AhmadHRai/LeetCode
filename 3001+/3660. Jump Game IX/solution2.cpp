class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n);

        suff[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(nums[i], suff[i + 1]);
        }

        vector<int> ans(n);

        int cur_max = 0;
        int l = 0;

        for (int i = 0; i < n; i++) {
            cur_max = max(cur_max, nums[i]);

            if (i == n - 1 || cur_max <= suff[i + 1]) {
                for (int j = l; j <= i; j++)
                    ans[j] = cur_max;
                l = i + 1;
            }
        }
        return ans;
    }
};
