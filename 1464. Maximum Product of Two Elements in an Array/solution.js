// Solution 0:
var maxProduct0 = function (nums) {
  var max = Math.max(...nums);
  nums.splice(nums.indexOf(max), 1);
  var max2 = Math.max(...nums);
  return (max - 1) * (max2 - 1);
};

// This has a time complexity of O(n) and a space complexity of O(1), where n is the length of the input array. This is because we need to
// iterate over the array twice to find the maximum and the second maximum elements, and we also need to modify the array by splicing out the
// maximum element

/* 
A better solution would be to use a single loop to find the maximum and the second maximum elements without modifying the array. This way, you can reduce the time complexity to O(n) and the space complexity to O(1). Here is a possible implementation in JavaScript:
*/

var maxProduct = function (nums) {
  // Initialize the maximum and the second maximum elements to the first two elements of the array
  let max = Math.max(nums[0], nums[1]);
  let max2 = Math.min(nums[0], nums[1]);
  // Loop over the array from the third element onwards
  for (let i = 2; i < nums.length; i++) {
    // If the current element is greater than the maximum element, update both the maximum and the second maximum elements
    if (nums[i] > max) {
      max2 = max;
      max = nums[i];
      // Else if the current element is greater than the second maximum element, update only the second maximum element
    } else if (nums[i] > max2) {
      max2 = nums[i];
    }
  }
  // Return the product of the maximum and the second maximum elements minus one
  return (max - 1) * (max2 - 1);
};
