class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = neededTime[0], max_neededTime = neededTime[0];
        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] != colors[i - 1]) {
                res -= max_neededTime;
                max_neededTime = 0;
            }
            res += neededTime[i];
            max_neededTime = max(max_neededTime, neededTime[i]);
        }
        return res - max_neededTime;
    }
};