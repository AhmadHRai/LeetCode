/**
 * Function to find the minimum number of turns required to print the given string
 * @param {string} s - The input string
 * @return {number} - The minimum number of turns required
 */
var strangePrinter = function(s) {
    const len = s.length; // Get the length of the string
    // Initialize the memoization table to store results for substrings
    const memo = Array(len).fill().map(() => Array(len).fill(0));

    // Recursive function to compute the minimum number of turns needed for substring s[l:r]
    function dp(l, r) {
        if (l > r) return 0; // Base case: empty substring requires 0 prints
        if (memo[l][r] !== 0) return memo[l][r]; // Return memoized result if already computed
        
        let min = 1 + dp(l + 1, r); // Assume printing s[l] separately and solve for s[l+1:r]

        // Iterate to find the optimal solution by combining prints if s[l] matches any s[i] where i > l
        for (let i = l + 1; i <= r; ++i) {
            if (s[i] === s[l]) {
                min = Math.min(min, dp(l + 1, i - 1) + dp(i, r));
            }
        }

        memo[l][r] = min; // Memoize the result for substring s[l:r]
        return min;
    }

    return dp(0, len - 1); // Compute the result for the entire string s[0:len-1]
};

/*
Approach Summary:
- Use dynamic programming with memoization to find the minimum number of turns needed to print the string.
- Define a recursive function `dp(l, r)` to find the minimum number of turns required to print the substring `s[l:r]`.
- Base case: an empty substring requires 0 prints.
- Use memoization to store and reuse results of previously computed substrings to avoid redundant calculations.
- Initially assume that each character needs a separate turn and then attempt to minimize this by combining prints based on matching characters.

Time Complexity:
- O(n^3), where n is the length of the string. The recursive function processes O(n^2) substrings and performs O(n) operations for each substring.

Space Complexity:
- O(n^2), where n is the length of the string. This is used for the memoization table to store results for all substrings.
*/
