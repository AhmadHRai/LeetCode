/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function (ratings) {
  const n = ratings.length;
  const candies = new Array(n).fill(1); // Initialize candies array with 1 candy for each child

  // Traverse from left to right
  for (let i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  // Traverse from right to left
  for (let i = n - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = Math.max(candies[i], candies[i + 1] + 1);
    }
  }

  // Calculate the total minimum number of candies needed
  return candies.reduce((total, num) => total + num, 0);
};

/* Testing - Example usage:
const ratings1 = [1, 0, 2];
const ratings2 = [1, 2, 2];
console.log(candy(ratings1)); // Output: 5
console.log(candy(ratings2)); // Output: 4
*/

/* 
Time complexity = O(n)
Space complexity = O(n) 
*/
