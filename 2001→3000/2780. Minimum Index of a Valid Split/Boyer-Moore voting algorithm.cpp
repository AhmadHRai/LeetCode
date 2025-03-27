class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int majority = nums[0];
        int count = 0;

        // find majority
        for (int num : nums) {
            if (num == majority)
                count++;
            else
                count--;

            if (count == 0) {
                majority = num;
                count = 1;
            }
        }

        // count majority
        int mCount = 0;
        for (int num : nums)
            if (num == majority)
                mCount++;

        // try to split
        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority)
                count++;
            if (count * 2 > (i + 1) &&
                (mCount - count) * 2 > (nums.size() - i - 1))
                return i;
        }

        return -1;
    }
};