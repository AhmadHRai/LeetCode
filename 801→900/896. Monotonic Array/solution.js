/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function (nums) {
  // Initialize flags for monotone increasing and monotone decreasing
  let increasing = true;
  let decreasing = true;

  // Iterate through the array starting from the second element
  for (let i = 1; i < nums.length; i++) {
    // If the current element is greater than the previous element,
    // it's not monotone decreasing
    if (nums[i] > nums[i - 1]) {
      decreasing = false;
    }
    // If the current element is less than the previous element,
    // it's not monotone increasing
    else if (nums[i] < nums[i - 1]) {
      increasing = false;
    }

    // If both flags are false, the array is neither increasing nor decreasing
    if (!increasing && !decreasing) {
      return false;
    }
  }

  // If either flag is true, the array is monotonic
  return increasing || decreasing;
};

// Test cases
// console.log(isMonotonic([1, 2, 2, 3])); // Output: true
// console.log(isMonotonic([6, 5, 4, 4])); // Output: true
// console.log(isMonotonic([1, 3, 2])); // Output: false

/* 
Time Complexity: O(n) - We iterate through the array once, where n is the length of the input array nums.
Space Complexity: O(1) - We use a constant amount of additional space to store the increasing and decreasing flags.
*/
