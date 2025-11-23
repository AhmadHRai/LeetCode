class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> g = v;
            for (int i = 0; i < 3; i++) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], v[i] + num);
            }
            v = move(g);
        }
        return v[0];
    }
};
