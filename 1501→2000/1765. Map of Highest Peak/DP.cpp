class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            int rows = isWater.size();
            int columns = isWater[0].size();
            // Large value to represent uninitialized heights
            const int INF = rows * columns;
    
            // Initialize the cellHeights matrix with INF (unprocessed cells)
            vector<vector<int>> cellHeights(rows, vector<int>(columns, INF));
    
            // Set the height of water cells to 0
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < columns; col++) {
                    if (isWater[row][col]) {
                        cellHeights[row][col] = 0;  // Water cells have height 0
                    }
                }
            }
    
            // Forward pass: updating heights based on top and left neighbors
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < columns; col++) {
                    // Initialize minimum neighbor distance
                    int minNeighborDistance = INF;
    
                    // Check the cell above
                    int neighborRow = row - 1;
                    int neighborCol = col;
                    if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                        minNeighborDistance =
                            min(minNeighborDistance,
                                cellHeights[neighborRow][neighborCol]);
                    }
    
                    // Check the cell to the left
                    neighborRow = row;
                    neighborCol = col - 1;
                    if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                        minNeighborDistance =
                            min(minNeighborDistance,
                                cellHeights[neighborRow][neighborCol]);
                    }
    
                    // Set the current cell's height as the minimum of its neighbors
                    // + 1
                    cellHeights[row][col] =
                        min(cellHeights[row][col], minNeighborDistance + 1);
                }
            }
    
            // Backward pass: updating heights based on bottom and right neighbors
            for (int row = rows - 1; row >= 0; row--) {
                for (int col = columns - 1; col >= 0; col--) {
                    // Initialize minimum neighbor distance
                    int minNeighborDistance = INF;
    
                    // Check the cell below
                    int neighborRow = row + 1;
                    int neighborCol = col;
                    if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                        minNeighborDistance =
                            min(minNeighborDistance,
                                cellHeights[neighborRow][neighborCol]);
                    }
    
                    // Check the cell to the right
                    neighborRow = row;
                    neighborCol = col + 1;
                    if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                        minNeighborDistance =
                            min(minNeighborDistance,
                                cellHeights[neighborRow][neighborCol]);
                    }
    
                    // Set the current cell's height as the minimum of its neighbors
                    // + 1
                    cellHeights[row][col] =
                        min(cellHeights[row][col], minNeighborDistance + 1);
                }
            }
    
            return cellHeights;  // Return the calculated cell heights
        }
    
    private:
        // Function to check if a cell is within grid bounds
        bool isValidCell(int row, int col, int rows, int columns) {
            return row >= 0 && col >= 0 && row < rows && col < columns;
        }
    };

/* 
Algorithm

    Initialize rows to the number of rows and columns to the number of columns of the isWater matrix.
    Initialize a 2D matrix, named cellHeights, of the same dimension as isWater. Set all of its cells to a large value, i.e. INF.
    Iterate over the cellHeights matrix and set the height of all water cells to 0.
    Loop with row from 0 to rows - 1:
        Loop with col from 0 to columns - 1:
            Initialize minNeighborDistance to INF.
            Find the neighbor above the current cell, i.e. neighborRow = row - 1, neighborCol = col.
            If the neighbor is valid, i.e. if it is not out of the bounds of the grid:
                Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
            Find the neighbor to the left of the current cell, i.e. neighborRow = row, neighborCol = col - 1.
            If the neighbor is valid:
                Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
            Set the height of the current cell to the minimum of its current value minNeighborDistance + 1.
    Perform the second pass over cellHeights moving in the opposite directions:
    Loop with row from rows - 1 to 0:
        Loop with col from columns - 1 to 0:
            Initialize minNeighborDistance to INF.
            Find the neighbor below the current cell, i.e. neighborRow = row + 1, neighborCol = col.
            If the neighbor is valid:
                Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
            Find the neighbor to the right of the current cell, i.e. neighborRow = row, neighborCol = col + 1.
            If the neighbor is valid:
                Set minNeighborDistance to the minimum of itself and cellHeights[neighborRow][neighborCol].
            Set the height of the current cell to the minimum of its current value minNeighborDistance + 1.
    Return cellHeights.

Complexity Analysis

Let m be the number of rows and n the number of columns in the isWater matrix.

    Time Complexity: O(m×n)
    We iterate over the cells of the matrix 3 times and perform constant-time operations, including comparisons and assignments, on each iteration. Therefore, the time complexity of the algorithm is O(m×n).

    Space Complexity: O(m×n)
    We use a 2D matrix cellHeights of size m×n to store the calculated heights resulting in a space complexity of O(m×n). Unlike the previous approach that used a queue as an additional data structure, this method only relies on the input grid and the resulting matrix, keeping the space complexity factor lower.

*/