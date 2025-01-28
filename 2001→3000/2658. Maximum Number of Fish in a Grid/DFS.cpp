class Solution {
    private:
        // Helper function to count the number of fishes in a connected component
        int calculateFishes(vector<vector<int>>& grid,
                            vector<vector<bool>>& visited, int row, int col) {
            // Check boundary conditions, water cells, or already visited cells
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
                grid[row][col] == 0 || visited[row][col]) {
                return 0;
            }
    
            // Mark the current cell as visited
            visited[row][col] = true;
    
            // Accumulate the fish count from the current cell and its neighbors
            return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
                   calculateFishes(grid, visited, row, col - 1) +
                   calculateFishes(grid, visited, row + 1, col) +
                   calculateFishes(grid, visited, row - 1, col);
        }
    
    public:
        int findMaxFish(vector<vector<int>>& grid) {
            int rows = grid.size(), cols = grid[0].size();
            int maxFishCount = 0;
    
            // A 2D vector to track visited cells
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
            // Iterate through all cells in the grid
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    // Start a DFS for unvisited land cells (fish available)
                    if (grid[row][col] > 0 && !visited[row][col]) {
                        maxFishCount = max(
                            maxFishCount, calculateFishes(grid, visited, row, col));
                    }
                }
            }
    
            // Return the maximum fish count found
            return maxFishCount;
        }
    };

/* 
Algorithm

Main Function: findMaxFish(vector<vector<int>>& grid)

    Initialize m and n to represent the number of rows and columns in grid.
    Create a 2D vector visited of size m x n to track visited cells, initialized to false.
    Initialize result to 0, which will store the maximum fish count from any connected component.
    Iterate through each cell (i, j) in the grid:
        If the cell is a water cell (grid[i][j] > 0) and has not been visited, call countFishes(grid, visited, i, j) to calculate the total fish in the connected component starting from (i, j).
        Update result to the maximum of result and the fish count returned by countFishes.
    Return result.

Helper Function: countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c)

    If the current cell (r, c), is out of bounds, is a land cell (grid[r][c] == 0), or, has already been visited (visited[r][c] == true), return 0.
    Mark the current cell (r, c) as visited by setting visited[r][c] = true.
    Recursively calculate the total fish count from all connected water cells:
        Call countFishes for the cells to the right, left, bottom, and top.
    Return the sum of fish in the current cell (grid[r][c]) and the fish counts from all valid neighboring cells.

Complexity Analysis

Let m be the number of rows and n be the number of columns in the grid.

    Time Complexity: O(m⋅n)

    In the worst case, where the grid is completely filled with water cells, the algorithm iterates through all m x n cells. For each cell, it performs a depth-first search (DFS) to calculate the total fish in the connected region. Therefore, the overall time complexity is O(m⋅n).

    Space Complexity: O(m⋅n)

    The algorithm uses a visited matrix of size m x n to track visited cells. Additionally, the depth-first search (DFS) can recurse to explore all connected cells, contributing to the space complexity. Hence, the overall space complexity is O(m⋅n).

*/