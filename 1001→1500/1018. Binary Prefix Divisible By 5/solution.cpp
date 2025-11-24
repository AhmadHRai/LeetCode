class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;

        int pfx = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pfx = ((pfx << 1) + nums[i]) % 5;
            ans.emplace_back(pfx == 0);
        }

        return ans;
    }
};
