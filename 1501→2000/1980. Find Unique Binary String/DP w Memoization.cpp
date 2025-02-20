class Solution {
    string help(vector<string>& nums, vector<string>& dp, int i, const string& s, set<string>& sets) {
        // Base case: If we've processed all positions
        if (i < 0) {
            return s; // Return the constructed string
        }
        // Special case for the last position
        if (i == 0) {
            // Check if the string is not in the set of input strings
            if (sets.find(s) == sets.end()) {
                return s; // Return the string if it's different
            }
            return ""; // Return empty string if it's not different
        }
        // Check if the result for this position is already computed
        if (!dp[i].empty()) {
            return dp[i]; // Return the memoized result
        }

        // Try appending '0' to the current string
        string op1 = s + '0';
        dp[i] = help(nums, dp, i - 1, op1, sets);
        if (!dp[i].empty()) {
            return dp[i]; // Return the result if appending '0' yields a different string
        }

        // Try appending '1' to the current string
        string op2 = s + '1';
        dp[i] = help(nums, dp, i - 1, op2, sets);
        return dp[i]; // Return the result if appending '1' yields a different string
    }

public:
    // Returns a binary string that differs from each string in the input vector
    string findDifferentBinaryString(vector<string>& nums) {
        // Set to store unique binary strings from the input vector
        set<string> sets(nums.begin(), nums.end());
        // Vector to store memoized results
        vector<string> dp(nums.size() + 1, "");
        string s = ""; // Initial empty string

        // Start the recursive process
        return help(nums, dp, nums.size(), s, sets);
    }
}
/*
Approach Summary:
    This solution uses a recursive approach with memoization to find a binary string that differs from each string in the input vector. It tries appending '0' and '1' to 
    the current string and checks if the resulting string is different from the input strings.

Complexity Analysis:
    Time Complexity: O(2^N), where N is the number of strings in the input vector, because in the worst case, all possible binary strings need to be explored.
    Space Complexity: O(2^N), for storing the memoized results and the recursion stack.
*/
