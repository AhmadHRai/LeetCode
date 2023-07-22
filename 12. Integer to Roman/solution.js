/**
 * @param {number} num
 * @return {string}
 */
const val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
const rom = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];

var intToRoman = function (num) {
  let ans = "";
  for (let i = 0; num; i++) {
    while (num >= val[i]) {
      ans += `${rom[i]}`;
      num -= val[i];
    }
  }
  return ans;
};

/* 
Time complexity: O(1) where 1 is a constant. The function loops through a fixed array of size 13 and 
performs constant time operations.
Space complexity: O(1) where 1 is a constant. The function uses a few variables of fixed size to store the 
answer string and the index.
*/
