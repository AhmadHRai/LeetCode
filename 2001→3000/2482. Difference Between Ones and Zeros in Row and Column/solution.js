// The function that takes a two-dimensional array of integers as input and returns a two-dimensional array of integers that represents the difference between the number of ones and zeros in each row and column of the input array
var onesMinusZeros = function (grid) {
  // The number of rows in the input array
  const m = grid.length;
  // The number of columns in the input array
  const n = grid[0].length;
  // A two-dimensional array of integers that stores the result, initialized to zero
  const res = Array.from({ length: m }, () => Array(n).fill(0));
  // A one-dimensional array of integers that stores the number of ones in each row, using the map and filter methods of the array
  const onesRow = grid.map((row) => row.filter((val) => val === 1).length);
  // A one-dimensional array of integers that stores the number of ones in each column, using the Array.from, map and filter methods of the array
  const onesCol = Array.from({ length: n }, (_, j) => grid.map((row) => row[j]).filter((val) => val === 1).length);

  // A loop that iterates over the rows of the result array
  for (let i = 0; i < m; i++) {
    // A loop that iterates over the columns of the result array
    for (let j = 0; j < n; j++) {
      // Calculate the difference between the number of ones and zeros in the current row and column and store it in the corresponding element of the result array
      // The difference is equal to the sum of the number of ones in the current row and column minus the sum of the number of zeros in the current row and column
      // The number of zeros in the current row is equal to the number of columns minus the number of ones in the current row
      // The number of zeros in the current column is equal to the number of rows minus the number of ones in the current column
      res[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
    }
  }

  // Return the result array
  return res;
};

/* 
Approach

    1. Initialize arrays rowOnes and colOnes to store the count of ones in each row and each column, respectively.
    2. Traverse the grid matrix to populate the rowOnes and colOnes arrays.
    3. Iterate through the grid matrix again and calculate each element of the diff matrix using the provided formula.
    4. Update each element of the grid matrix with the calculated difference.
    5. Return the modified grid matrix as the resulting diff.
    

Complexity

    Time complexity: O(m x n), where (m) is the number of rows and (n) is the number of columns in the grid matrix.
    Space complexity: (O(m + n) for the rowOnes and colOnes arrays.
*/
