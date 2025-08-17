/**
 * @param {number} n
 * @param {number} k
 * @param {number} maxPts
 * @return {number}
 */
var new21Game = function (n, k, maxPts) {
  if (k === 0 || n >= k + maxPts) return 1;
  const dp = new Array(n + 1).fill(0);
  dp[0] = 1;
  let sum = 1;
  for (let i = 1; i <= n; ++i) {
    dp[i] = sum / maxPts;
    if (i < k) sum += dp[i];
    if (i - maxPts >= 0) sum -= dp[i - maxPts];
  }
  let res = 0;
  for (let i = k; i <= n; ++i) res += dp[i];
  return res;
};
