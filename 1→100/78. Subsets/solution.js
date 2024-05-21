/**
 * @param {number[]} nums
 * @return {number[][]}
 *
 * This function generates all possible subsets of a given array of numbers.
 * It uses a recursive approach to explore all subsets, starting from an empty subset and gradually adding elements.
 *
 * Approach:
 * - Initialize an array `subs` to store all subsets.
 * - Define a helper function `generateSubsets` that will handle the recursion.
 * - The helper function takes the current state of the subset, the index of the current element, and the results array.
 * - For each call, add the current subset to the results.
 * - Iterate over the remaining elements, add each element to the current subset, recurse, and then remove the element.
 *
 * Complexity Analysis:
 * - Time Complexity: O(2^n), where n is the number of elements in the input array.
 *   This is because there are 2^n possible subsets.
 * - Space Complexity: O(n), which is the depth of the recursion tree.
 *
 * Example:
 * Input: nums = [1, 2, 3]
 * Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
 */
var subsets = function (nums) {
  const subs = []; // Array to store all subsets
  const sub = []; // Temporary array to store current subset

  // Helper function to generate subsets recursively
  const generateSubsets = (nums, i, sub, subs) => {
    subs.push([...sub]); // Add the current subset to the results
    for (let j = i; j < nums.length; j++) {
      sub.push(nums[j]); // Include nums[j] in the current subset
      generateSubsets(nums, j + 1, sub, subs); // Recurse with the next element
      sub.pop(); // Backtrack to explore other subsets
    }
  };

  // Start the recursion with the initial parameters
  generateSubsets(nums, 0, sub, subs);
  return subs; // Return the list of all subsets
};

/* 
Explanation

In this JavaScript code:

    The subsets function initializes an array subs to store all subsets and an empty array sub to keep track of the current subset being constructed.
    The generateSubsets function is a helper function that uses recursion to explore all possible subsets.
    For each element, it adds the element to the current subset, recurses to explore further, and then backtracks by removing the element.
    The subsets are constructed and stored in the subs array, which is returned as the final result


Complexity Analysis

    Time Complexity: O(2^n), where n is the number of elements in the input array. This is due to the exponential number of subsets.
    Space Complexity: O(n), which is the depth of the recursion tree.
*/
