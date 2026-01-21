class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            int bit = 0;
            while (x & (1 << bit))
                bit++;
            ans.push_back(x > 2 ? x ^ (1 << (bit - 1)) : -1);
        }
        return ans;
    }
};
