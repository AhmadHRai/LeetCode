/**
 * @param {string} s
 * @return {number}
 */
var minDeletions = function (s) {
  const charCount = new Array(26).fill(0);

  // Count the frequency of each character in the string
  for (const char of s) {
    const index = char.charCodeAt(0) - "a".charCodeAt(0);
    charCount[index]++;
  }

  const frequencySet = new Set();

  let deletions = 0;

  // Iterate through the frequency of characters
  for (let freq of charCount) {
    while (freq > 0 && frequencySet.has(freq)) {
      // If the frequency already exists in the set, decrement it and increase deletions
      freq--;
      deletions++;
    }

    // Add the current frequency to the set
    frequencySet.add(freq);
  }

  return deletions;
};

/* 
    Time Complexity: O(n) - We iterate through the string once to count character frequencies and then iterate through the frequencies, both taking linear time.
    Space Complexity: O(1) - The space used for charCount and frequencySet is constant because the alphabet size is fixed (26 characters).
*/
