class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] >= nums[1]) {
            return false;
        }
        int count = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                count++;
            }
        }
        return count == 3;
    }
};
