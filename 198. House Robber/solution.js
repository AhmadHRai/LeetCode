/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
  // If the array is empty, return 0 as the base case
  if (nums.length === 0) return 0;
  // If the array has only one element, return that element as the base case
  if (nums.length === 1) return nums[0];
  // Initialize two variables to store the previous two results
  // prev1 is the maximum amount of money that can be robbed from the first i-1 houses
  // prev2 is the maximum amount of money that can be robbed from the first i-2 houses
  let prev1 = nums[0];
  let prev2 = Math.max(nums[0], nums[1]);
  // Loop over the array from the third element
  for (let i = 2; i < nums.length; i++) {
    // Calculate the maximum amount of money that can be robbed from the first i houses as the maximum of two options:
    // 1. Rob the i-th house and the maximum amount of money that can be robbed from the first i-2 houses
    // 2. Do not rob the i-th house and the maximum amount of money that can be robbed from the first i-1 houses
    let curr = Math.max(prev1 + nums[i], prev2);
    // Update the previous two results with the current result and the previous result
    prev1 = prev2;
    prev2 = curr;
  }
  // Return the last result as the answer
  return prev2;
};

/* 
Complexity:

    Space:  O(1), 
    Time: O(n) 
*/
