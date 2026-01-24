class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxSum = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            maxSum = max(maxSum, nums[i] + nums[nums.size() - 1 - i]);
        }

        return maxSum;
    }
};
