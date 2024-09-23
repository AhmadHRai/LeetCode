/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
function minExtraChar(s, dictionary) {
  // Initialize a memoization array to store results for subproblems
  const dp = new Array(s.length + 1).fill(-1);

  // Helper function to compute the minimum extra characters
  function minExtraCharHelper(i) {
    // Base case: no characters left means no extra characters
    if (i === 0) {
      return 0;
    }

    // Return the cached result if it exists
    if (dp[i] !== -1) {
      return dp[i];
    }

    // Start with the worst case: one extra character for the current character
    dp[i] = 1 + minExtraCharHelper(i - 1);

    // Check against each word in the dictionary
    for (const w of dictionary) {
      // If the current substring matches the word
      if (i >= w.length && s.slice(i - w.length, i) === w) {
        // Update dp[i] to the minimum extra characters needed
        dp[i] = Math.min(dp[i], minExtraCharHelper(i - w.length));
      }
    }

    return dp[i]; // Return the computed minimum for the current position
  }

  // Start the computation from the end of the string
  return minExtraCharHelper(s.length);
}

/**
 * 
 * Time Complexity (TC): O(NML), where N is the length of the input string s, M is the number of words in the dictionary, and L is the average length of words in the dictionary. This is because each position in the string is visited once for each word in the dictionary.
 * Space Complexity (SC): O(N), where N is the length of the input string s. We use an array dp of size N for memoization, and the recursive call stack can go up to a depth of N.
 */
