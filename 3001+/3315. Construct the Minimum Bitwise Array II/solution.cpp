class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            if (num == 2) {
                ans[i] = -1;
                continue;
            }

            int count = 0;

            while ((num & 1) == 1) {
                count++;
                num >>= 1;
            }

            ans[i] = nums[i] - (1 << (count - 1));
        }

        return ans;
    }
};
