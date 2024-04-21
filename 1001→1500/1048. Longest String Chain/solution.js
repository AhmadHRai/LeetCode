/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function (words) {
  // Sort the words by length in ascending order
  words.sort((a, b) => a.length - b.length);

  // Initialize a map to store the longest chain ending with each word
  const dp = new Map();

  // Initialize the maximum chain length to 1
  let maxChainLength = 1;

  // Loop through each word in the sorted array
  for (const word of words) {
    let currentMax = 1; // The minimum chain length is 1

    // Generate all possible predecessor words by removing one character
    for (let i = 0; i < word.length; i++) {
      const predecessor = word.slice(0, i) + word.slice(i + 1);
      if (dp.has(predecessor)) {
        // Update the currentMax based on predecessors
        currentMax = Math.max(currentMax, dp.get(predecessor) + 1);
      }
    }

    // Update the dp map for the current word
    dp.set(word, currentMax);

    // Update the overall maximum chain length
    maxChainLength = Math.max(maxChainLength, currentMax);
  }

  return maxChainLength;
};

// Time complexity: O(N * L^2), where N is the number of words and L is the average word length
// Space complexity: O(N), where N is the number of words
