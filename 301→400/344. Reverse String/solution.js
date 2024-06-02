/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString2 = function (s) {
  return s.reverse();
};

/**
 * Reverses a string in-place.
 *
 * @param {character[]} s - An array of characters representing the string.
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
  // Use two pointers approach to reverse the string in-place
  for (let [a, b] = [0, s.length - 1]; a < b; a++, b--) {
    [s[a], s[b]] = [s[b], s[a]]; // Swap characters at positions a and b
  }
};

/* 
Algorithm:
    Two Pointers: Use two pointers, a starting from the beginning (0) and b starting from the end (s.length - 1).
    Swap Characters: Iterate while a is less than b, swapping characters s[a] and s[b] using destructuring assignment [s[a], s[b]] = [s[b], s[a]].
    This approach ensures that the string is reversed in-place without needing extra space.

Complexity:
    Time Complexity: O(n) - where n is the length of the array s. The function iterates over half of the array (n/2 swaps), making it linear in time complexity.
    Space Complexity: O(1) - The function uses only a constant amount of extra space, primarily for the two pointers a and b.
*/
