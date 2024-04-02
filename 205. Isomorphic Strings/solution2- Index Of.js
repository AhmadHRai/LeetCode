/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
  // Check if the lengths of the two strings are equal. If not, they cannot be isomorphic.
  if (s.length !== t.length) return false;

  // Iterate over each character in the strings.
  for (let i = 0; i < s.length; i++) {
    // For each character in 's', find its first occurrence in 's' and compare it with the first occurrence of the corresponding character in 't'.
    // If the positions are not the same, the strings are not isomorphic.
    if (s.indexOf(s[i]) !== t.indexOf(t[i])) return false;
  }
  // If the loop completes without finding any mismatches, the strings are isomorphic.
  return true;
};

/* 
Approach Summary

    This solution checks if the first occurrence of each character in the first string matches the first occurrence of the 
    corresponding character in the second string. It does this by iterating through the strings and using the `indexOf` method to find 
    the first occurrence of each character. If the positions of the first occurrences do not match, the function returns false, 
    indicating that the strings are not isomorphic. If all characters have matching first occurrences, the function returns true.

Time Complexity Analysis

    The time complexity is O(n^2), where n is the length of the strings. This is because for each character in the strings, the 
    `indexOf` method is called, which itself has a time complexity of O(n).

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input strings.

 */
