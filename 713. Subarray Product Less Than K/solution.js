/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function (nums, k) {
  let count = 0;
  let start = 0;
  let product = 1;

  // Iterate through the array using a sliding window approach
  for (let end = 0; end < nums.length; end++) {
    // Multiply the current product by the next number in the array
    product *= nums[end];
    // While the product is greater than or equal to k and the start is less than or equal to the end
    while (product >= k && start <= end) {
      // Divide the product by the number at the start of the window
      product /= nums[start];
      // Move the start pointer to the right
      start++;
    }
    // Increment the count by the number of subarrays that can be formed with the current window
    count += end - start + 1;
  }

  // Return the total count of subarrays with product less than k
  return count;
};

/* 
Approach Summary

    The algorithm uses a sliding window approach to iterate through the array, maintaining a window of elements whose product is less 
    than `k`. The window is expanded by moving the `end` pointer to the right and shrunk by moving the `start` pointer to the right if 
    the product of the elements in the window exceeds `k`. The count of all possible subarrays that satisfy the condition is maintained 
    and returned at the end.

    The algorithm starts by initializing `count` to 0, `start` to 0, and `product` to 1. It then enters a loop that continues until 
    `end` reaches the end of the array. Inside the loop, `product` is multiplied by the current element, and a while loop checks if 
    `product` is greater than or equal to `k`. If it is, `product` is divided by the element at the `start` index, and `start` is 
    incremented. After each iteration of the outer loop, the count of all possible subarrays is incremented by the difference between 
    `end` and `start` plus 1.

Time Complexity Analysis

    The time complexity of this algorithm is O(n), where n is the length of the input array `nums`. This is because each element in the 
    array is visited at most twice: once by the `end` pointer and once by the `start` pointer.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input array.

 */
