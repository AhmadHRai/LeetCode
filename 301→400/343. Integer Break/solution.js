/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function (n) {
  let memo = new Map();

  function dp(n) {
    if (n == 1 || n == 2) return 1;
    if (memo.has(n)) return memo.get(n);

    let q = 0;
    for (let i = 1; i <= n / 2; i++) {
      q = Math.max(q, i * Math.max(n - i, dp(n - i)));
    }
    memo.set(n, q);
    return q;
  }
  return dp(n);
};

/*
The time complexity is O(n^2).
There are n/2 loops for the 1st recursive call, (n-1)/2 for the 2nd call, and so on.
Therefore the total number of loops is: n/2 + (n-1)/2 + (n-2)/2 + (n-3)/2 + (n-4)/2 + ... + (n-(n-3))/2
This sum evaluates to an upper bound of: (n*2 - n(n+1)/2)/2
which simplifies to (n^2-n)/4. Which is O(n^2)
 */
