class Solution {
    string help(vector<string>& nums, vector<string>& dp, int i,const string& s, set<string>& sets) {
        if (i < 0) {
            return s;
        }
        if (i == 0) {
            if (sets.find(s) == sets.end()) {
                return s;
            }
            return "";
        }
        if (!dp[i].empty()) {
            return dp[i];
        }
        string op1 = s + '0';
        dp[i] = help(nums, dp, i - 1, op1, sets);
        if (!dp[i].empty()) {
            return dp[i];
        }
        string op2 = s + '1';
        dp[i] = help(nums, dp, i - 1, op2, sets);
        return dp[i];
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> sets(nums.begin(), nums.end());
        vector<string> dp(nums.size() + 1, "");
        string s = "";
        return help(nums, dp, nums.size(), s, sets);
    }
};
