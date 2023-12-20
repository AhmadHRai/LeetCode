/**
 * @param {number[]} prices
 * @param {number} money
 * @return {number}
 */
var buyChoco = function (prices, money) {
  // First sort the array
  prices.sort(function (a, b) {
    return a - b;
  });

  // get the sum of the 2 lowest priced chocolates
  const sum = prices[0] + prices[1];

  // compare the sum if its affordable (money>=sum)
  return money >= sum ? money - sum : money;
};

/* 
The time complexity of this code is O(n log n), where n is the length of the input array prices. This is because we use the built-in sort function, which has an average time complexity 
of O (n log n) in JavaScript.

The space complexity of this code is O(1), because we do not create any new data structures or allocate any dynamic memory.
*/
