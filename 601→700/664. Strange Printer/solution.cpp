class Solution {
public:
    // Function to find the minimum number of turns required to print the given string
    int strangePrinter(string s) {
        int len = s.length(); // Get the length of the string
        vector<vector<int>> memo(len, vector<int>(len, 0)); // Memoization table to store results of subproblems

        // Recursive lambda function to compute the minimum prints needed for substring s[l:r]
        function<int(int, int)> dp = [&](int l, int r) -> int {
            if (l > r) return 0; // Base case: empty substring requires 0 prints
            if (memo[l][r] != 0) return memo[l][r]; // Return memoized result if already computed

            int minPrints = 1 + dp(l + 1, r); // Initial assumption: print s[l] separately and solve for s[l+1:r]

            // Iterate to find the optimal point to combine prints if s[l] matches any s[i] where i > l
            for (int i = l + 1; i <= r; ++i) {
                if (s[i] == s[l]) {
                    minPrints = min(minPrints, dp(l + 1, i - 1) + dp(i, r));
                }
            }

            memo[l][r] = minPrints; // Memoize the result for substring s[l:r]
            return minPrints;
        };

        return dp(0, len - 1); // Compute the result for the entire string s[0:len-1]
    }
};

/*
Approach Summary:
- Use dynamic programming with memoization to find the minimum number of turns required to print the string.
- Define a recursive function `dp(l, r)` to find the minimum number of turns needed to print the substring `s[l:r]`.
- Base case: an empty substring requires 0 prints.
- Use memoization to store and reuse results of previously computed substrings.
- The function initially assumes that each character needs a separate turn and tries to minimize this by checking if characters can be combined based on matching characters.

Time Complexity:
- O(n^3), where n is the length of the string. The recursive function processes O(n^2) substrings and performs O(n) operations for each substring.

Space Complexity:
- O(n^2), where n is the length of the string. This is used for the memoization table to store results for all substrings.
*/
