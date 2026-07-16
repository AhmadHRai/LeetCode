class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maximum = 0, n = nums.size();
        for (int& num : nums) {
            maximum = max(num, maximum);
            num = gcd(num, maximum);
        }
        sort(nums.begin(), nums.end());

        long long sum = 0;

        for (int left = 0, right = n - 1; left < right; left++, right--)
            sum += gcd(nums[left], nums[right]);

        return sum;
    }
};
