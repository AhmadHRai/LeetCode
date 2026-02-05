class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int targetIndex = ((i + nums[i]) % n + n) % n;
            ans[i] = nums[targetIndex];
        }

        return ans;
    }
};
