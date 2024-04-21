var countBits = function (n) {
  const ans = new Array(n + 1).fill(0); // Initialize an array to store the counts

  for (let i = 1; i <= n; i++) {
    // Use the observation to calculate the count for 'i'
    ans[i] = ans[i >> 1] + (i & 1);
  }

  return ans;
};

/**
 * Approach:
*   Create an array ans of length n + 1 to store the counts.
    Loop from i = 1 to n and calculate the count of 1's for each i using the observation.
    To calculate the count for i, use ans[i >> 1] to get the count for i/2 and add i & 1 to it to account for the last bit.
 */

/**
 Time Complexity:

    The solution uses a single loop that iterates from i = 1 to n.
    Inside the loop, there are constant time operations to calculate the count of 1's for each i.
    Therefore, the overall time complexity is O(n).

Space Complexity:

    The solution uses an array ans of length n + 1 to store the counts.
    The size of the ans array is directly proportional to the input value n.
    Therefore, the space complexity is O(n).
 */
