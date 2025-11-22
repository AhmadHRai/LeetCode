class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;

        for (int num : nums) {
            if (num % 3) {
                res++;
            }
        }

        return res;
    }
};
