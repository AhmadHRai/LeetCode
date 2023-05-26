// Define a function that takes a string as a parameter and returns the longest palindromic substring in it
var longestPalindrome = function(s) {
    // If the string is empty, return an empty string
    if (s.length === 0) {
      return "";
    }
    
    // Get the length of the string
    let n = s.length;
    // Create a two-dimensional array to store the boolean values of whether a substring is palindromic or not
    let dp = Array(n).fill().map(() => Array(n).fill(false));
    
    // Initialize the start index and the maximum length of the longest palindromic substring
    let start = 0;
    let maxLen = 1;
    
    // Every string of length 1 is a palindrome, so mark them as true in the array
    for (let i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    
    // Check for strings of length 2, and mark them as true in the array if they are palindromes
    // Also update the start index and the maximum length accordingly
    for (let i = 0; i < n - 1; i++) {
      if (s[i] === s[i+1]) {
        dp[i][i+1] = true;
        start = i;
        maxLen = 2;
      }
    }
    
    // Check for strings of length > 2, and mark them as true in the array if they are palindromes
    // A substring is palindromic if its first and last characters are equal and its inner substring is also palindromic
    // Also update the start index and the maximum length accordingly
    for (let k = 3; k <= n; k++) {
      for (let i = 0; i < n - k + 1; i++) {
        let j = i + k - 1;
        if (dp[i+1][j-1] && s[i] === s[j]) {
          dp[i][j] = true;
          if (k > maxLen) {
            start = i;
            maxLen = k;
          }
        }
      }
    }
    
    // Return the longest palindromic substring by slicing the original string from the start index to the end index
    return s.slice(start, start + maxLen);
  };
  
/*   The time complexity of this solution is O(n^2), where n is the length of the string. This is because we use 
two nested loops to iterate through all possible substrings, and each iteration takes O(1) time.
  
The space complexity of this solution is O(n^2), because we use a two-dimensional array to store n * n boolean 
values in the worst case.
 */  
  