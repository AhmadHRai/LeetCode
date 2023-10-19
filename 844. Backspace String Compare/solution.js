/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function (s, t) {
  // initialize two pointers for s and t
  let i = s.length - 1;
  let j = t.length - 1;
  // loop until both pointers reach the beginning
  while (i >= 0 || j >= 0) {
    // skip the characters that are deleted by '#'
    let skipS = 0; // count the number of '#' in s
    while (i >= 0) {
      if (s[i] === "#") {
        skipS++; // increment the count
        i--; // move the pointer left
      } else if (skipS > 0) {
        skipS--; // decrement the count
        i--; // move the pointer left
      } else {
        break; // no more '#' to skip
      }
    }
    let skipT = 0; // count the number of '#' in t
    while (j >= 0) {
      if (t[j] === "#") {
        skipT++; // increment the count
        j--; // move the pointer left
      } else if (skipT > 0) {
        skipT--; // decrement the count
        j--; // move the pointer left
      } else {
        break; // no more '#' to skip
      }
    }
    // compare the remaining characters
    if (i >= 0 && j >= 0) {
      if (s[i] !== t[j]) {
        return false; // not equal, return false
      }
    } else {
      // one of the strings is empty
      if (i >= 0 || j >= 0) {
        return false; // not equal, return false
      }
    }
    // move to the next character
    i--;
    j--;
  }
  // both strings are equal
  return true;
};
