class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int arr[100001][2];

        memset(&arr, 0, sizeof(arr));

        int n = nums.size(), res = 0;

        for (int i = 0; i < n; ++i) {
            int& num = nums[i];

            if ((num & 1) == 0) {
                res = (res + arr[num >> 1][1]) % 1000000007;
            }
            if (num <= 50000) {
                arr[num][1] =
                    (arr[num][1] + arr[num << 1][0]) % 1000000007;
            }
            ++arr[num][0];
        }
        return res;
    }
};
