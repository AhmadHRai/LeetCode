class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cover_count(n + 1, 0);

        // Mark coverage increments and decrements
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            cover_count[l] += 1;
            if (r + 1 < n) {
                cover_count[r + 1] -= 1;
            }
        }

        // Prefix sum to get coverage count per index
        for (int i = 1; i < n; ++i) {
            cover_count[i] += cover_count[i - 1];
        }

        // Check if coverage is enough for each element
        for (int i = 0; i < n; ++i) {
            if (cover_count[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
}; //TC O(N+M) SC O(N)