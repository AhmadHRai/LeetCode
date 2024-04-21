/**
 * @param {number[]} prices
 * @param {number} money
 * @return {number}
 */
var buyChoco = function (prices, money) {
  // Initialize the lowest and second lowest prices to the maximum possible value
  let lowestPrice = Number.MAX_VALUE;
  let secondLowestPrice = Number.MAX_VALUE;

  // Loop over the prices array
  for (let price of prices) {
    // If the current price is lower than the lowest price, update both the lowest and second lowest prices
    if (price < lowestPrice) {
      secondLowestPrice = lowestPrice;
      lowestPrice = price;
    }
    // Else if the current price is lower than the second lowest price, update only the second lowest price
    else if (price < secondLowestPrice) {
      secondLowestPrice = price;
    }
  }

  // Get the sum of the two lowest priced chocolates
  const sum = lowestPrice + secondLowestPrice;

  // Return the remaining money after buying the chocolates, or the original money if the chocolates are not affordable
  return sum <= money ? money - sum : money; // Changed this line from Math.min(money, money - sum) to fix the negative number returned
};

/* 
The time complexity is O(n), where n is the length of the input array prices. This is because we iterate over the array once, and perform constant-time operations in each iteration.
The space complexity is O(1), because we do not create any new data structures or allocate any dynamic memory. We only use a fixed number of variables, regardless of the input size.
*/
