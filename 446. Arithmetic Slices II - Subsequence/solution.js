/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function (nums) {
  // Get the length of the input array
  const n = nums.length;
  // Initialize the total count of arithmetic slices to zero
  let total_count = 0;

  // Create a dynamic programming array of maps
  // Each map stores the number of arithmetic subsequences ending at a certain index with a certain difference
  const dp = new Array(n).fill().map(() => new Map());

  // Loop over the array from the second element
  for (let i = 1; i < n; ++i) {
    // Loop over the array from the first element to the current element
    for (let j = 0; j < i; ++j) {
      // Calculate the difference between the current element and the previous element
      const diff = nums[i] - nums[j];

      // If the previous element has a subsequence with the same difference
      if (dp[j].has(diff)) {
        // Add the number of such subsequences to the current element's map
        dp[i].set(diff, (dp[i].get(diff) || 0) + dp[j].get(diff));
        // Add the number of such subsequences to the total count of arithmetic slices
        // This is because each subsequence can be extended by one element to form a slice
        total_count += dp[j].get(diff);
      }

      // Increment the number of subsequences ending at the current element with the current difference by one
      // This is because each pair of elements can form a subsequence of length two
      dp[i].set(diff, (dp[i].get(diff) || 0) + 1);
    }
  }

  // Return the total count of arithmetic slices
  return total_count;
};

/* 
Complexity:
    The time complexity is O(n^2), where n is the length of the input array. This is because the code uses two nested loops to iterate over the array, and performs constant-time 
    operations in each iteration.
    
    The space complexity is O(n^2), because the code creates a dynamic programming array of maps, and the size of the maps can be up to O(n) in the worst case. This is because 
    the difference between any two elements can be any integer in the range [-1000, 1000], and there can be up to n elements with the same difference.
*/
