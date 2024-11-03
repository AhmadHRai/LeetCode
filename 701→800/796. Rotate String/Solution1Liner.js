/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function (s, goal) {
  // Check if the lengths are equal and if `goal` is a substring of `s + s`
  return s.length === goal.length && (s + s).includes(goal);
};

/* 
Explanation

    The solution first checks if s and goal have the same length, since strings of different lengths can’t be rotations of each other.
    Then, it concatenates s with itself, forming a new string s + s. If goal is a rotation of s, it must appear as a substring in this concatenated string.
        For example, if s = "abcde" and goal = "cdeab", then s + s = "abcdeabcde", and "cdeab" appears as a substring of "abcdeabcde".

Complexity Analysis

    Time Complexity: O(n), where nn is the length of s. The includes method checks for a substring match in O(n) time.
    Space Complexity: O(n) for the temporary concatenated string s + s.
*/
