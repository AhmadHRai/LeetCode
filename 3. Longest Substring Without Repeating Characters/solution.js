/**
 * @param {string} s
 * @return {number}
 */
// Define a function that takes a string as a parameter and returns the length of the longest substring without repeating characters
var lengthOfLongestSubstring = function(s) {
    // Initialize two pointers to track the start and end of the current substring
    let left = 0;
    let right = 0;
    // Initialize a variable to store the maximum length of the substring
    let maxLen = 0;
    // Create a set to store the characters in the current substring
    let chars = new Set();
    
    // Loop until the end pointer reaches the end of the string
    while (right < s.length) {
        // If the character at the end pointer is not in the set
        if (!chars.has(s.charAt(right))) {
            // Add it to the set
            chars.add(s.charAt(right));
            // Move the end pointer to the right by one
            right++;
            // Update the maximum length by comparing it with the size of the set
            maxLen = Math.max(maxLen, chars.size);
        } else {
            // If the character at the end pointer is in the set, it means there is a repetition
            // Remove the character at the start pointer from the set
            chars.delete(s.charAt(left));
            // Move the start pointer to the right by one
            left++;
        }
    }
    
    // Return the maximum length of the substring without repeating characters
    return maxLen;
};

/* 
The time complexity of this solution is O(n), where n is the length of the string. This is because we use one 
loop to iterate through the string, and each lookup and insertion in the set takes O(1) time.

The space complexity of this solution is O(min(m, n)), where m is the size of the alphabet. This is because we 
use a set to store at most m distinct characters in the worst case.
 */