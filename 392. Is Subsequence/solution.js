/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function (s, t) {
  let sPointer = 0;
  let tPointer = 0;

  while (sPointer < s.length && tPointer < t.length) {
    if (s[sPointer] === t[tPointer]) {
      sPointer++;
    }
    tPointer++;
  }

  return sPointer === s.length;
};

/* 
Time Complexity: The time complexity of this solution is O(t), where t is the length of string t. In the worst case, you might need to iterate through the entire string t to find the subsequence s.

Space Complexity: The space complexity is O(1) because we only use a constant amount of extra space to store the pointers and variables.
*/
