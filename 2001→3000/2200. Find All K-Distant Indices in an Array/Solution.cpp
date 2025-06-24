class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;

        int m = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++) {
            if(nums[j] == key) {
                int l = max(m, j - k);
                m = min(n - 1, j+k) + 1;
                for(int i = l; i < m; i++) res.push_back(i);
            }
        }


        return res;
    }
};