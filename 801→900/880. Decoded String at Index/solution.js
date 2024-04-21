/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var decodeAtIndex = function (s, k) {
  for (let i = 0, j = 0, n; true; i++)
    if (s[i] < 10) {
      n = ~~s[i] * j;
      if (k > n) j = n;
      else return decodeAtIndex(s, k % j || j);
    } else if (++j === k) return s[i];
};

/* 
Time Complexity:
    The function iterates through the characters of the input string S once, so the time complexity is O(n), where n is the length of S.

Space Complexity:
    The function uses a constant amount of additional space for variables like i, j, and n, so the space complexity is O(1).
*/
