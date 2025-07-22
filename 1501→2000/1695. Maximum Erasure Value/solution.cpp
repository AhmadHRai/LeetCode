class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> lastIndex;
        vector<int> prefixSum(nums.size() + 1, 0);

        int maxScore = 0;
        int l = 0;
        for (int r = 0; r < (int)nums.size(); ++r) {
            prefixSum[r + 1] = prefixSum[r] + nums[r];
            if (lastIndex.find(nums[r]) != lastIndex.end()) {
                l = max(l, lastIndex[nums[r]] + 1);
            }
            maxScore = max(maxScore, prefixSum[r + 1] - prefixSum[l]);
            lastIndex[nums[r]] = r;
        }

        return maxScore;
    }
};
