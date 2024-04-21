/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  s = s.trim().split(' ');
  return s[s.length - 1].length;
};

/* 
Approach Summary

    This solution trims the input string and splits it into an array of words. It then returns the length of the last word in the 
    array. This approach is more concise but may be less efficient for very long strings due to the overhead of splitting the string 
    into an array.

Time Complexity Analysis

    The time complexity is O(n), where n is the length of the input string `s`. This is because the `split` operation iterates through 
    the entire string.

Space Complexity Analysis

    The space complexity is O(n), where n is the number of words in the input string `s`. This is because the `split` operation creates 
    an array of words.

 */

