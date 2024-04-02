var lengthOfLastWord = function (s) {
  var r = s.length - 1;
  while (s[r] === ' ') --r;
  var l = r;
  while (l >= 0 && s[l] !== ' ') --l;
  return r - l;
};

/* 
Approach Summary

    This solution iterates through the input string from the end to the beginning, looking for the last non-space character. It then 
    iterates from that point to the beginning of the string, counting the number of characters until it encounters a space. This 
    approach is efficient and does not require additional space for data structures.

Time Complexity Analysis

    The time complexity is O(n), where n is the length of the input string `s`. This is because in the worst case, the algorithm 
    iterates through the entire string twice.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input string.

 */
