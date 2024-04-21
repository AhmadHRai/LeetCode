var findContentChildren = function (g, s) {
  // Sort the array g in ascending order
  g.sort((a, b) => a - b);
  // Sort the array s in ascending order
  s.sort((a, b) => a - b);
  // Initialize a pointer j to track the index of g, and a variable res to store the result
  let j = 0,
    res = 0;
  // Loop through each element in the array s
  for (let num of s) {
    // If the current element is greater than or equal to the element at index j of g
    if (num >= g[j]) {
      // Increment the result by one
      res++;
      // Increment the pointer j by one
      j++;
    }
  }
  // Return the result
  return res;
};

/*
Approach:
 
    The code uses a greedy approach to solve the problem. The main idea is to sort both arrays in ascending order, and then assign the smallest cookie to the least greedy child. The 
    code uses a pointer to track the index of the array g, and a variable to store the result. The code loops through the array s, and checks if the current cookie can satisfy the 
    current child. If yes, the code increments the result and the pointer. If no, the code skips the current cookie and moves on to the next one.

Complexity:

    The time complexity of this code is O(n log n + m log m), where n is the length of the array g, and m is the length of the array s. This is because the code uses the built-in sort 
    method, which takes O(n log n) time for the array g, and O(m log m) time for the array s. The code also loops through the array s once, which takes O(m) time. Therefore, the total 
    time complexity is O(n log n + m log m).

    The space complexity of this code is O(1), because the code does not use any extra space other than the input and output. The code only uses a constant amount of extra space for the 
    variables j, res, and num. Therefore, the total space complexity is O(1).
*/
