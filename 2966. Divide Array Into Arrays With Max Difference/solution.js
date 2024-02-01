/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[][]}
 */
var divideArray = function (nums, k) {
  // Sort the array of numbers in ascending order
  nums.sort((a, b) => a - b);
  // Initialize an empty array to store the result
  let res = [];
  // Loop through the array from the third element, skipping every three elements
  for (let i = 2; i < nums.length; i += 3) {
    // If the difference between the current element and the previous second element is greater than k, return an empty array
    if (nums[i] - nums[i - 2] > k) return [];
    // Otherwise, push an array of the previous second, previous first, and current elements to the result array
    res.push([nums[i - 2], nums[i - 1], nums[i]]);
  }
  // Return the result array
  return res;
};

/* 
Complexity:
    The time complexity is O(n log n), where n is the length of the input array. This is because the code uses the sort method, which has a time complexity of O (n log n) in the 
    worst case. The code also uses a loop to iterate over the array, which has a time complexity of O (n) in the worst case. Therefore, the total time complexity is O 
    (n log n + n), which is equivalent to O (n log n).
    
    The space complexity is O(n), because the code uses an array to store the result, which has a size of O (n) in the worst case. The code also uses some auxiliary variables, 
    but they do not affect the overall space complexity.
*/
