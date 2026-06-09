class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min, max] = ranges::minmax(nums);
        return (long long)(max - min) * k;
    }
};
