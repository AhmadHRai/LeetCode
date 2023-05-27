/**
 * @param {string} s
 * @return {string}
 */

// This function returns the longest palindromic substring in s
// A palindrome is a string that is the same when read forward or backward
// For example, "racecar" and "abba" are palindromes
var longestPalindrome = function(s) {
    // Initialize a variable to store the longest palindrome found so far
    var max = '';
    // Loop through each character in s
    for (var i = 0; i < s.length; i++) {
      // This loop is to take into account 
      // different types of palindromes like 'aba' and 'abba'
      // We will try to expand around the center of each character
      // and check if the substring is a palindrome
      for (var j = 0; j < 2; j++) {
        // Set the left and right pointers to the center of the current character
        var left = i;
        var right = i + j;
        // While the left and right pointers are within the bounds of s
        // and the characters at those positions are equal
        while (s[left] && s[left] === s[right]) {
          // Move the left pointer one step to the left
          left--;
          // Move the right pointer one step to the right
          right++;
        }
        // At this point, we have either reached the end of s
        // or found a mismatching character
        // The palindrome is the substring from left + 1 to right - 1
        // Note that we need to adjust the indices because of the previous steps
        // For example, if s = "sabbad", then after finding "abba"
        // we have left = 0 and right = 5, but the actual indices of "abba" are 1 and 4
        // So we need to add 1 to left and subtract 1 from right
        // The length of the palindrome is then right - left - 1
        if ((right - left - 1) > max.length) {
          // If the length of the palindrome is greater than max.length
          // then update max to be that palindrome
          max = s.substring(left + 1, right);
        }
          
      }
    }
    // Return the longest palindrome found in s
    return max;
  };
  
  // The time complexity of this solution is O(N^2), where N is the length of s
  // This is because we loop through each character in s, and for each character
  // we expand around the center up to O(N) times in the worst case
  // The space complexity of this solution is O(1), because we only use a constant amount of extra space to store max
  