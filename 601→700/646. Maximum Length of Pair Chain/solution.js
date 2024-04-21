/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function (pairs) {
  // Sort the pairs based on the ending value (righti)
  pairs.sort((a, b) => a[1] - b[1]);

  const n = pairs.length;
  const dp = new Array(n).fill(1); // Initialize an array to store the chain lengths

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (pairs[j][1] < pairs[i][0]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  return Math.max(...dp); // Find the maximum chain length
};

// Test cases
const pairs1 = [
  [1, 2],
  [2, 3],
  [3, 4],
];
console.log(findLongestChain(pairs1)); // Output: 2

const pairs2 = [
  [1, 2],
  [7, 8],
  [4, 5],
];
console.log(findLongestChain(pairs2)); // Output: 3
