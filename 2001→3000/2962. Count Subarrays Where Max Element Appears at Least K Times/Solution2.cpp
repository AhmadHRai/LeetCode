class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0, start = 0;
        int max_elements_in_window  = 0;

        for( int end = 0; end < nums.size(); end++) {
            if(nums[end] == maxElement) {
                max_elements_in_window ++;
            }
            while(max_elements_in_window  == k) {
                if(nums[start] == maxElement) {
                    max_elements_in_window --;
                }
                start++;
            }
            ans += start;
        }

        return ans;
    }
};