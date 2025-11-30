class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate the total sum of the array
        for (int num : nums) {
            totalSum = (num + totalSum) % p;
        }

        int target = totalSum % p;

        // If total sum modulo p is already 0, no need to remove anything
        if (target == 0)
            return 0;

        // Step 2: Use a hash map to track prefix sum modulo p
        unordered_map<int, int> modMap;
        modMap[0] =
            -1; // handle the case when the prefix sum itself is the answer
        int currentSum = 0,
            minLen = n; // Initialize minLen to max possible value

        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate the remainder we need to remove
            int needed = (currentSum - target + p) % p;

            // If we have seen the needed remainder in the map, we can form a
            // subarray to remove
            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }

            // Store the current remainder and its index
            modMap[currentSum] = i;
        }

        // Step 4: Return result. If no valid subarray was found, return -1
        return minLen == n ? -1 : minLen;
    }
};
