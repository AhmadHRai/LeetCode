/**
 * @param {string} s
 * @return {number}
 */
var maxLengthBetweenEqualCharacters = function (s) {
  // Initialize the maximum length of a substring between two equal characters to -1 (the defaulted number if there are no equal characters)
  let max = -1;
  // Define an object to store the last occurrence index of each character in the string
  const lastOccurrence = {};

  // Loop through each character in the string
  for (let i = 0; i < s.length; i++) {
    // Get the current character
    const char = s[i];
    // Check if the current character has appeared before
    if (char in lastOccurrence) {
      // If yes, calculate the length of the substring between the current and the previous occurrence of the character
      // and update the maximum length if it is larger
      max = Math.max(max, i - lastOccurrence[char] - 1);
    } else {
      // If no, store the current index as the last occurrence of the character
      lastOccurrence[char] = i;
    }
  }

  // Return the maximum length of a substring between two equal characters
  return max;
};

/* 
Approach:
    The code uses a hash table approach to solve the problem. The main idea is to store the last occurrence index of each character in the string, and then loop through the string to 
    find the maximum length of a substring between two equal characters.

Complexity:
    
    Time: The time complexity of this code is O(n), where n is the length of the input string s. This is because the code loops through each character in the string once, and performs 
    constant time operations such as accessing and updating the object, comparing and assigning the numbers. The code does not use any nested loops or recursion that would increase the 
    time complexity.

    Space: The space complexity of this code is O(m), where m is the number of unique characters in the input string s. This is because the code uses an object to store the last 
    occurrence index of each character, which can have up to m keys. The code also uses a constant amount of extra space for the variables max, char, and i. Therefore, the total space 
    complexity is O(m).

*/
