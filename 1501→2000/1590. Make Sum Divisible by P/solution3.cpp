class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;

        for (int x : nums)
            sum += x;

        int target = sum % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> rem_ind;
        rem_ind[0] = -1;

        long long currSum = 0;
        int minSize = n;

        for (int i = 0; i < n; i++) {
            currSum = (currSum + nums[i]) % p;
            int diff = (currSum - target + p) % p;

            if (rem_ind.count(diff)) {
                minSize = min(minSize, i - rem_ind[diff]);
            }
            rem_ind[currSum] = i;
        }

        return (minSize == n) ? -1 : minSize;
    }
};
