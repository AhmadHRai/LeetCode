class Solution {
public:
    static vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        if (n == 1)
            return nums;
        int R[n];
        int l = 0, r = 0;
        for (int x : nums) {
            nums[l] = R[r] = x;
            l += (x < pivot);
            r += (x > pivot);
        }
        int m = n - r - l;
        auto it_m = nums.begin() + l;
        fill(it_m, it_m + m, pivot);
        copy(R, R + r, it_m + m);
        return nums;
    }
};
