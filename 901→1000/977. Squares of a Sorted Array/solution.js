/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (A) {
  // Initialize an empty array to store the result
  const result = [];
  // Initialize two pointers, 'head' at the start of the array and 'tail' at the end
  let head = 0;
  let tail = A.length - 1;

  // Continue the loop as long as 'head' is not greater than 'tail'
  while (head <= tail) {
    // Compare the square of the numbers at 'head' and 'tail'
    if (A[head] ** 2 > A[tail] ** 2) {
      // If the square at 'head' is larger, push it to the result array and move 'head' to the next position
      result.push(A[head++] ** 2);
    } else {
      // Otherwise, push the square at 'tail' to the result array and move 'tail' to the previous position
      result.push(A[tail--] ** 2);
    }
  }

  // Since the result array is constructed in reverse order, reverse it to get the final sorted array of squares
  return result.reverse();
};

/* 
Approach:

    We use two pointers, head and tail, to traverse the array from both ends.
    It compares the squares of the numbers at the current positions of head and tail.
    The larger square is added to the result array, and the corresponding pointer is moved inward.
    This process continues until head and tail meet in the middle, ensuring that all squares are considered and added to the result array in descending order.
    Finally, the result array is reversed because the squares are added in reverse order.

Complexity Analysis:

    Time Complexity:    The time complexity is O(n) because each element in the array is visited once. The loop runs for as many elements as there are in the array.
    Space Complexity:   The space complexity is O(n) because a new array, result, is used to store the squares of the elements. In the worst-case scenario, result will have 
    the same number of elements as the input array A

*/
