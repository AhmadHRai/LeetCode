class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int freq = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    freq++;
                }

                int len = j - i + 1;

                if (freq > len / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
