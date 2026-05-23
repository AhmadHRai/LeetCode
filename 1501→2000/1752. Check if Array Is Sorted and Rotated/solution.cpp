class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 1;

        if (n==1) return true;

        for(int i = 1; i < n*2; i++) {
            if (nums[(i-1)%n] <= nums[i%n]) {
                count++;
            } else {
                count = 1;
            }

            if(count == n) return true;
        }
        return false;
    }
};
