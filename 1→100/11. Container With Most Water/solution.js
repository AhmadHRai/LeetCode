/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  // Use a more descriptive name for the variable that stores the maximum area
  let maxArea = 0;
  // Use more descriptive names for the variables that store the left and right pointers
  let left = 0;
  let right = height.length - 1;
  // Loop until the left and right pointers meet
  while (left < right) {
    // Update the maximum area by comparing it with the current area
    // Use parentheses to group the expressions
    maxArea = Math.max(maxArea, Math.min(height[left], height[right]) * (right - left));
    // Move the pointer that points to the shorter line
    // Use the increment and decrement operators
    height[left] <= height[right] ? left++ : right--;
  }
  // Return the maximum area
  return maxArea;
};

/* 
Time complexity: O(n) where n is the length of the height array. The function uses a two-pointer approach to loop through the array once and performs constant time operations.
Space complexity: O(1) where 1 is a constant. The function uses a few variables of fixed size to store the maximum area, the left and right pointers, and the current area.
 */
