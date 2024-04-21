/**
 * @param {number} n
 * @return {number}
 */
const MOD = 1e9 + 7;
var countOrders = function (n) {
  let count = 1;
  for (let i = 2; i <= n; i++) {
    count = (count * (2 * i - 1) * i) % MOD;
  }
  return count;
};

/* 
    Time Complexity: O(n)
    The algorithm iterates once through all the orders from 2 to n, performing constant-time operations for each. Therefore, the time complexity is linear.

    Space Complexity: O(1)
    Only a constant amount of extra space is used (i.e., the variable count), making the space complexity constant.
 */
