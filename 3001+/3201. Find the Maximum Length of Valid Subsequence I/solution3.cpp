class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                odd++;
            else
                even++;
            if (i < n - 1 && (nums[i] & 1) != (nums[i + 1] & 1))
                ans++;
        }
        return max(ans, max(even, odd));
    }
};