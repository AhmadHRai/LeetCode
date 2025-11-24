class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans = vector<bool>(n, false);
        int num = 0;

        for (int i = 0; i < n; i++) {
            num = (num * 2 + nums[i]) % 10;
            if (num % 5 == 0)
                ans[i] = true;
        }

        return ans;
    }
};
