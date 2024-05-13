/**
 * Calculates the score after flipping rows in a binary matrix.
 *
 * @param {number[][]} grid - A 2D array representing the binary matrix.
 * @return {number} - The total score after flipping rows.
 */
var matrixScore = function (grid) {
  // Initialize variables for the number of rows and columns in the grid.
  let m = grid.length;
  let n = grid[0].length;

  // Calculate the initial score assuming all rows have been flipped.
  let res = Math.pow(2, n - 1) * m;

  // Iterate through each column starting from the second one.
  for (let j = 1; j < n; j++) {
    // Initialize a counter for the number of rows where the first element equals the current element.
    let curr = 0;

    // Count the number of rows where the first element equals the current element.
    for (let i = 0; i < m; i++) {
      curr += grid[i][0] === grid[i][j] ? 1 : 0;
    }

    // Update the result by adding the maximum possible score for the current column.
    res += Math.max(curr, m - curr) * Math.pow(2, n - 1 - j);
  }

  // Return the final score.
  return res;
};

/* 
Approach and Intuition:

    The goal is to calculate the score after flipping rows in a binary matrix. Each row in the matrix represents a unique identifier, and flipping a row means changing all 
    its bits. The score is calculated based on the assumption that flipping rows makes them more significant.

    Initial Score Calculation: The initial score is calculated assuming all rows have been flipped. This is done by multiplying the number of rows (m) by 2^(n-1) because 
    each bit in the binary representation contributes to the score, and we start counting from the least significant bit.

    Column-wise Analysis: For each column starting from the second one, the algorithm counts how many rows have the same value in both the first and current column. This 
    count is used to determine how many rows need to be flipped in the current column to maximize the score.

    Maximizing Score: The score for each column is maximized by choosing either all rows with the same value in the first and current column or all rows with the opposite 
    value. This choice is made by taking the maximum of curr (rows with matching values) and m - curr (rows with differing values), then multiplying by 2^(n-1-j) to account 
    for the decreasing significance of bits as we move towards the right.

Complexity:
    Time Complexity Analysis:
        The outer loop iterates over each column once, resulting in a time complexity of O(n).
        The inner loop iterates over each row once, resulting in a time complexity of O(m).
        Since there are two nested loops, the overall time complexity is O(m*n).
    Space Complexity Analysis:
        The space complexity is O(1) since no additional space proportional to the input size is used. The only variable that grows with the input size is res, but it 
        doesn't exceed the bounds of what can be stored in a single integer variable.
*/
