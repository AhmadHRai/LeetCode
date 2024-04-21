/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  // Trim any leading or trailing spaces
  s = s.trim();

  // Initialize a variable to store the length of the last word
  let length = 0;

  // Iterate the string from right to left
  for (let i = s.length - 1; i >= 0; i--) {
    // Break the loop when a space is encountered after a word
    if (s[i] === ' ' && length > 0) {
      break;
    }

    // Increment the length if a non-space character is found
    if (s[i] !== ' ') {
      length++;
    }
  }

  // Return the length of the last word
  return length;
};

/* 
Approach Summary

    This solution trims any leading or trailing spaces from the input string and then iterates through the string from right to left. 
    It counts the length of the last word by incrementing a counter for each non-space character encountered. The loop breaks when a 
    space is found after a word, ensuring that only the last word's length is counted.

Time Complexity Analysis

    The time complexity is O(n), where n is the length of the input string `s`. This is because in the worst case, the algorithm 
    iterates through the entire string.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input string.

 */
