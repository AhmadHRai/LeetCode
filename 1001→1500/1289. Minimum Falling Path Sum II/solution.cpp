class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        int prevMin1 = INT_MAX;
        int prevMin2 = INT_MAX;

        // Initialize prevMin1 and prevMin2 with the minimum values in the first row
        for (int j = 0; j < cols; ++j) {
            if (grid[0][j] < prevMin1) {
                prevMin2 = prevMin1;
                prevMin1 = grid[0][j];
            }
            else if (grid[0][j] < prevMin2) {
                prevMin2 = grid[0][j];
            }
        }
        
        // Iterate through each row starting from the second row
        for (int i = 1; i < rows; ++i) {
            int currMin1 = INT_MAX;
            int currMin2 = INT_MAX;

            // For each cell in the current row, calculate the minimum falling path sum by adding the current cell value to the minimum of the two previous cells in the same column
            for (int j = 0; j < cols; ++j) {
                int prevMin = grid[i-1][j] != prevMin1 ? prevMin1 : prevMin2;
                grid[i][j] += prevMin;

                // Update currMin1 and currMin2 with the minimum values in the current row
                if (grid[i][j] < currMin1) {
                    currMin2 = currMin1;
                    currMin1 = grid[i][j];
                }
                else if (grid[i][j] < currMin2) {
                    currMin2 = grid[i][j];
                }
            }
            prevMin2 = currMin2;
            prevMin1 = currMin1;
        }

        // Return the minimum falling path sum from the last row
        return prevMin1;
    }
};

/* 
Approach:

    This solution iteratively calculates the minimum falling path sum for each cell in the grid by adding the current cell value to the minimum of the two previous cells in the same column. It keeps track of the two minimum values in the previous row to ensure that the path does not fall through the same cell twice.

Complexity:

    Time Complexity: O(rows * cols), where rows is the number of rows in the grid and cols is the number of columns. This is because the algorithm iterates through each cell in the grid once.

    Space Complexity: O(1), as the algorithm modifies the input grid in-place and does not use any additional space that scales with the input size.

This approach is efficient for solving the problem within the given constraints, as it systematically calculates the minimum falling path sum for each cell in the grid.
*/