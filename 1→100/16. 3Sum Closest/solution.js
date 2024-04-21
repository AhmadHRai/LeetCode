/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// Function to find the sum of three integers in nums that is closest to target
var threeSumClosest = function (nums, target) {
  // Sort the array in ascending order
  nums.sort((a, b) => a - b);
  // Initialize the result as the sum of the first three elements
  let result = nums[0] + nums[1] + nums[2];
  // Loop through the array from left to right
  for (let i = 0; i < nums.length - 2; i++) {
    // Skip duplicate elements
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    // Use two pointers to find the other two elements
    let left = i + 1;
    let right = nums.length - 1;
    // While the pointers do not meet
    while (left < right) {
      // Calculate the sum of the current three elements
      let sum = nums[i] + nums[left] + nums[right];
      // If the sum is equal to the target, return it
      if (sum === target) return sum;
      // If the sum is closer to the target than the previous result, update the result
      if (Math.abs(sum - target) < Math.abs(result - target)) result = sum;
      // If the sum is smaller than the target, move the left pointer to the right
      if (sum < target) left++;
      // If the sum is larger than the target, move the right pointer to the left
      else right--;
    }
  }
  // Return the final result
  return result;
};

/* 
Approach:

This solution is based on the idea of sorting the array and using two pointers to find the optimal pair for each element, while updating the result with the closest sum to the target.


Complexity:
    
    The time complexity of this solution is O(n^2), where n is the length of the array.
    The space complexity is O(1), as we only use constant extra space.

*/
