/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function (sentence) {
  // Split the sentence into words by spaces
  const words = sentence.split(' ');
  const n = words.length; // Number of words in the sentence

  // Iterate through each word in the sentence
  for (let i = 0; i < n; i++) {
    // Check if the last character of the current word matches
    // the first character of the next word (circular, so last word checks with first word)
    if (words[i][words[i].length - 1] !== words[(i + 1) % n][0]) {
      return false; // If any pair doesn't match, sentence is not circular
    }
  }

  return true; // If all pairs match, sentence is circular
};

/*
Approach:

    The solution splits the sentence into an array of words and checks if the sentence is circular. 
    A sentence is circular if the last character of each word matches the first character of the 
    next word, with the last word linking back to the first word. The modulo operation `(i + 1) % n`
    allows this circular check by ensuring the last word compares to the first word.

Complexity:

    Time Complexity: O(n), where `n` is the number of characters in the sentence. 
    Splitting the sentence and iterating through the words each take linear time.
    
    Space Complexity: O(n), as we store the words in an array of length proportional to the input sentence length.
*/
