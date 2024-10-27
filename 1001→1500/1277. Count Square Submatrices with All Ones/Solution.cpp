class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Get the number of rows and columns
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Create a DP table of the same size as the matrix
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int totalCount = 0; // This will hold the total count of squares
        
        // Iterate through each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Only process cells that are `1`
                if (matrix[i][j] == 1) {
                    // If we're at the first row or first column, the max square is just the value itself
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // Corner case for the first row/column
                    } else {
                        // Update the dp value based on the min of the three neighbors
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Add the current square size to the total count
                    totalCount += dp[i][j];
                }
            }
        }
        
        // Return the total count of square submatrices
        return totalCount;
    }
};

/*
Complexity Analysis:

    Time Complexity: O(m × n), where mm is the number of rows and nn is the number of columns. We go through each cell of the matrix exactly once.
    Space Complexity: O(m × n) for the DP table. However, if we only need the current and previous rows, we can optimize the space to O(n).


Explanation of Key Lines:

    Initialization: We define the size of the matrix and create a dp table filled with zeros.
    Loop through each cell: We iterate through each cell in the matrix.
    Base case: For the first row or column, if the value is 1, we can only have a square of size 1.
    DP Update: For other cells, we determine the size of the largest square ending at that cell by looking at the sizes of squares that can extend to the left, above, and diagonally up-left.
    Count Total Squares: As we update the dp table, we also keep a running total of all squares found.
*/