// Jul 7 2023
/**
 * @param {number[]} weights
 * @param {number} k
 * @return {number}
 */
var putMarbles = function (weights, k) {
  const costs = [];
  // Creating all cuts costs array
  for (let i = 0; i < weights.length - 1; i++) {
    costs.push(weights[i] + weights[i + 1]);
  }
  // We sort costs, since we need k lowest and k highest
  costs.sort((a, b) => a - b);

  let result = 0;
  // We need only difference, so no need to slice array
  // We running it once, and adding difference to result
  for (let i = 0; i < k - 1; i++) {
    result += costs[costs.length - 1 - i] - costs[i];
  }

  return result;
};
