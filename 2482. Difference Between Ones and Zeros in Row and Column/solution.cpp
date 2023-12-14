// The class definition for the solution
class Solution {
public:
    // The function that takes a vector of vectors of integers as input and returns a vector of vectors of integers that represents the difference between the number of ones and zeros in each row and column of the input vector
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // The number of rows in the input vector
        int m = grid.size();
        // The number of columns in the input vector
        int n = grid[0].size();
        // A vector of vectors of integers that stores the result, initialized to zero
        vector<vector<int>> res(m, vector<int>(n, 0));
        // A vector of integers that stores the number of ones in each row, initialized to zero
        vector<int> onesRow(m, 0);
        // A vector of integers that stores the number of ones in each column, initialized to zero
        vector<int> onesCol(n, 0);

        // A loop that iterates over the rows of the input vector
        for (int i = 0; i < m; i++) {
            // Counting the number of ones in the current row and storing it in the corresponding index of the onesRow vector
            onesRow[i] = count(grid[i].begin(), grid[i].end(), 1);
        }

        // A loop that iterates over the columns of the input vector
        for (int j = 0; j < n; j++) {
            // A loop that iterates over the rows of the input vector
            for (int i = 0; i < m; i++) {
                // Adding the value of the current element to the corresponding index of the onesCol vector
                onesCol[j] += grid[i][j];
            }
        }

        // A loop that iterates over the rows of the result vector
        for (int i = 0; i < m; i++) {
            // A loop that iterates over the columns of the result vector
            for (int j = 0; j < n; j++) {
                // Calculating the difference between the number of ones and zeros in the current row and column and storing it in the corresponding element of the result vector
                // The difference is equal to the sum of the number of ones in the current row and column minus the sum of the number of zeros in the current row and column
                // The number of zeros in the current row is equal to the number of columns minus the number of ones in the current row
                // The number of zeros in the current column is equal to the number of rows minus the number of ones in the current column
                res[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
            }
        }

        // Returning the result vector
        return res;        
    }
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