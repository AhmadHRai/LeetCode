/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
function minExtraChar(s, dictionary) {
  const dp = new Array(s.length + 1).fill(-1);

  function minExtraCharHelper(i) {
    if (i === 0) {
      return 0;
    }

    if (dp[i] !== -1) {
      return dp[i];
    }

    dp[i] = 1 + minExtraCharHelper(i - 1);

    for (const w of dictionary) {
      if (i >= w.length && s.slice(i - w.length, i) === w) {
        dp[i] = Math.min(dp[i], minExtraCharHelper(i - w.length));
      }
    }

    return dp[i];
  }

  return minExtraCharHelper(s.length);
}

/**
 * 
Time Complexity (TC): O(NML), where N is the length of the input string s, M is the number of words in the dictionary, and L is the average length of words in the dictionary. This is because each position in the string is visited once for each word in the dictionary.
Space Complexity (SC): O(N), where N is the length of the input string s. We use an array dp of size N for memoization, and the recursive call stack can go up to a depth of N.
 */
