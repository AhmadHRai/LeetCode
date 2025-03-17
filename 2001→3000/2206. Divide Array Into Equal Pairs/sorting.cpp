class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Sort array to group equal elements together
        sort(nums.begin(), nums.end());

        // Check consecutive pairs in sorted array
        for (int pos = 0; pos < nums.size(); pos += 2) {
            // If any pair doesn't match, we can't form n equal pairs
            if (nums[pos] != nums[pos + 1]) {
                return false;
            }
        }

        // All pairs found successfully
        return true;
    }
};