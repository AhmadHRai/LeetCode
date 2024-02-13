/**
 * @param {string[]} words
 * @return {string}
 */
var firstPalindrome = function (words) {
  // Loop over the array of words
  for (const word of words) {
    // Check if the word is equal to its reverse
    if (word === word.split("").reverse().join(""))
      // If yes, return the word
      return word;
  }
  // If no palindrome is found, return an empty string
  return "";
};

/* 
Complexity:
    The time complexity of the code is O(nk), where n is the size of the input array and k is the maximum length of any word in the array. This is because we need to loop over the 
    array once, which takes O(n) time, and for each word, we need to reverse it, which takes O(k) time. The comparison and return operations are constant time.

    The space complexity of the code is O(k), where k is the same as above. This is because we need to create a new array of characters when we split the word, which takes O(k) space. 
    The rest of the variables and operations do not depend on the input size.
*/
