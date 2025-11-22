class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += min(num % 3, 3 - num % 3);
        }

        return res;
    }
};
