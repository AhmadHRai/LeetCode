class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int gMin = nums.front(), gMax = nums.front();

        for (auto& n : nums) {
            gMin = min(gMin, n);
            gMax = max(gMax, n);
        }

        return (long long)(gMax - gMin) * k;
    }
};
