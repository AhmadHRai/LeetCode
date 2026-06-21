/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function (costs, coins) {
  const max = Math.max(...costs);
  const counts = new Array(1 + max).fill(0);

  for (const cost of costs) {
    counts[cost]++;
  }

  let count = 0;

  for (let cost = 1; cost <= max; cost++) {
    if (counts[cost] === 0) continue;

    while (cost <= coins && counts[cost]) {
      count++;
      coins -= cost;
      counts[cost]--;
    }

    if (cost > coins) break;
  }

  return count;
};
