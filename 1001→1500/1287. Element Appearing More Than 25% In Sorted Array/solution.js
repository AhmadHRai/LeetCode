// The function that takes an array of integers as input and returns the integer that occurs more than 25% of the time in the array, or -1 if there is no such integer
var findSpecialInteger = function (arr) {
  // A constant that stores the window size, which is one-fourth of the array length, rounded down
  const ws = Math.floor(arr.length / 4);
  // A loop that iterates over the array elements until the window size from the end
  for (let i = 0; i < arr.length - ws; i++) {
    // If the current element and the element at the window size distance from the current element are the same, they form a window that contains more than 25% of the same element
    if (arr[i] === arr[i + ws]) {
      // Return the current element as the answer
      return arr[i];
    }
  }
  // If the loop ends without finding any window that contains more than 25% of the same element, return -1 as the answer
  return -1;
};

/* 
Approach:
    The approach is based on the idea of using a sliding window technique to find the integer that occurs more than 25% of the time in the array. A sliding window 
    is a subarray of the array that has a fixed size and moves by one element at a time. The size of the window is one-fourth of the array length, rounded down, 
    because any element that occurs more than 25% of the time must appear at least once in such a window. To find the element, we use a loop to iterate over the 
    array elements until the window size from the end and check if the current element and the element at the window size distance from the current element are 
    the same. If they are, they form a window that contains more than 25% of the same element and we return the current element as the answer. If they are not, we 
    move the window by one element and repeat the process. If the loop ends without finding any window that contains more than 25% of the same element, we return 
    -1 as the answer.

Complexity:
    The time complexity of this solution is O(N), where N is the length of the input array. This is because we need to iterate over the array elements once and 
    perform constant time operations on each element. The space complexity is O(1), where 1 is a constant. This is because we only need to store the window size 
    and the loop variables, which take constant space.
*/
