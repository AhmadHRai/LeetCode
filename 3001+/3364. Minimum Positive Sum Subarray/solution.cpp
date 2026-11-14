class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int best = INT_MAX;

        for (int len = l; len <= r; len++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (i >= len)
                    sum -= nums[i - len];
                if (i >= len - 1 && sum > 0 && sum < best)
                    best = sum;
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};
