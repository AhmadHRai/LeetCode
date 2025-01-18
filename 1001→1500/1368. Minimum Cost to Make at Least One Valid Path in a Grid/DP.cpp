class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        vector<vector<int>> minChanges(numRows, vector<int>(numCols, INT_MAX));

        // Initialize all cells with max value
        minChanges[0][0] = 0;

        while (true) {
            // Store previous state to check for convergence
            vector<vector<int>> prevState = minChanges;

            // Forward pass: check cells coming from left and top
            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numCols; col++) {
                    // Check cell above
                    if (row > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row - 1][col] +
                                    (grid[row - 1][col] == 3 ? 0 : 1));
                    }
                    // Check cell to the left
                    if (col > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col - 1] +
                                    (grid[row][col - 1] == 1 ? 0 : 1));
                    }
                }
            }

            // Backward pass: check cells coming from right and bottom
            for (int row = numRows - 1; row >= 0; row--) {
                for (int col = numCols - 1; col >= 0; col--) {
                    // Check cell below
                    if (row < numRows - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row + 1][col] +
                                    (grid[row + 1][col] == 4 ? 0 : 1));
                    }
                    // Check cell to the right
                    if (col < numCols - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col + 1] +
                                    (grid[row][col + 1] == 2 ? 0 : 1));
                    }
                }
            }

            // If no changes were made in this iteration, we've found optimal
            // solution
            if (prevState == minChanges) {
                break;
            }
        }

        return minChanges[numRows - 1][numCols - 1];
    }
};


/* 
Complexity Analysis

Let n be the number of rows and m be the number of columns in the grid.

    Time Complexity: O((n⋅m)2)

    The algorithm has an outer loop that continues until convergence, where k is the number of iterations needed. In each iteration, we perform a forward pass and a backward pass through the entire grid, each taking O(n⋅m) time. Therefore, the total time complexity is O(n⋅m⋅k).

    The value of k depends on the grid configuration and in the worst case could be proportional to n⋅m, making the worst-case time complexity O((n⋅m)2).

    Space Complexity: O(n⋅m)

    The algorithm uses two 2D arrays - minChanges and prevState, each of size n×m. No additional space scaling with input size is needed. Therefore, the total space complexity is O(n⋅m).

*/