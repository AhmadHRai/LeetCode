class Solution {
    // The function that takes a two-dimensional array of integers as input and returns a two-dimensional array of integers that represents the difference between the number of ones and zeros in each row and column of the input array
    public int[][] onesMinusZeros(int[][] grid) {
        // The number of rows in the input array
        int m = grid.length;
        // The number of columns in the input array
        int n = grid[0].length;
        // A two-dimensional array of integers that stores the result, initialized to zero
        int[][] res = new int[m][n];
        // A one-dimensional array of integers that stores the number of ones in each row, initialized to zero
        int[] onesRow = new int[m];
        // A one-dimensional array of integers that stores the number of ones in each column, initialized to zero
        int[] onesCol = new int[n];

        // A loop that iterates over the rows of the input array
        for (int i = 0; i < m; i++) {
            // A loop that iterates over the columns of the input array
            for (int j = 0; j < n; j++) {
                // If the current element is 1, increment the number of ones in the current row by 1, otherwise do nothing
                onesRow[i] += (grid[i][j] == 1) ? 1 : 0;
                // Add the value of the current element to the number of ones in the current column
                onesCol[j] += grid[i][j];
            }
        }

        // A loop that iterates over the rows of the result array
        for (int i = 0; i < m; i++) {
            // A loop that iterates over the columns of the result array
            for (int j = 0; j < n; j++) {
                // Calculate the difference between the number of ones and zeros in the current row and column and store it in the corresponding element of the result array
                // The difference is equal to the sum of the number of ones in the current row and column minus the sum of the number of zeros in the current row and column
                // The number of zeros in the current row is equal to the number of columns minus the number of ones in the current row
                // The number of zeros in the current column is equal to the number of rows minus the number of ones in the current column
                res[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
            }
        }

        // Return the result array
        return res;        
    }
}

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