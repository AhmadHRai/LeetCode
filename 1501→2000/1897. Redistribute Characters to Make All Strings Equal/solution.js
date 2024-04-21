/**
 * @param {string[]} words
 * @return {boolean}
 */
var makeEqual = function (words) {
  if (words.length === 1) {
    return true;
  }

  let totalCharCount = 0;
  for (const s of words) {
    totalCharCount += s.length;
  }

  if (totalCharCount % words.length !== 0) {
    return false;
  }

  let myMap = new Array(26).fill(0);
  for (const s of words) {
    for (const c of s) {
      myMap[c.charCodeAt(0) - "a".charCodeAt(0)]++;
    }
  }

  for (const i of myMap) {
    if (i % words.length !== 0) {
      return false;
    }
  }

  return true;
};

/* 
Intuition

The problem is asking whether it is possible to make all strings in the given array equal by performing specific operations. The operations allow moving characters from one string to another.
Approach

    First, we check if the length of the array is 1. If it is, all strings are already equal, so we return true.
    Calculate the total character count across all strings.
    If the total character count is not divisible by the number of strings, it is impossible to make them equal, so return false.
    Initialize an array myMap to count the occurrences of each character.
    Traverse all strings and update the character count in myMap.
    Check if each character count is divisible evenly by the number of strings. If any character count is not divisible, return false.
    If all checks pass, return true.

Complexity

    Time complexity: The time complexity is O(N * M), where N is the number of strings and M is the average length of the strings. This is because we traverse each character in each string.

    Space complexity: The space complexity is O(1) since the character count array has a constant size of 26 (assuming lowercase English letters).

*/
