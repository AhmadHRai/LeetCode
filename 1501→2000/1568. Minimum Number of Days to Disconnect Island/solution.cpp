class Solution {
public:
    // Direction vectors for moving in four directions (right, left, down, up)
    vector<int> dx = {1, -1, 0, 0}; // Movement in x-direction
    vector<int> dy = {0, 0, 1, -1}; // Movement in y-direction

    // Depth-First Search (DFS) function to explore all cells in an island
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid
        vis[x][y] = 1; // Mark the cell (x, y) as visited
        // Explore all four possible directions
        for (int a = 0; a < 4; a++) {
            int nx = x + dx[a]; // Calculate new x-coordinate
            int ny = y + dy[a]; // Calculate new y-coordinate
            // Check if the new position is within bounds, not visited, and is land
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny]) {
                dfs(nx, ny, grid, vis); // Recursively visit the new cell
            }
        }
    }

    // Function to count the number of islands in the grid
    int count_islands(vector<vector<int>> &grid) {
        int islands = 0; // Counter for the number of islands
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited grid initialization

        // Iterate over each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is land and not yet visited, perform DFS
                if (!vis[i][j] && grid[i][j]) {
                    dfs(i, j, grid, vis); // Explore the island
                    islands++; // Increment the island count
                }
            }
        }
        return islands; // Return the total number of islands
    }

    // Function to find the minimum number of days to make all islands connected or 0 islands
    int minDays(vector<vector<int>>& grid) {
        int islands = count_islands(grid); // Get the initial number of islands
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Check for the cases where no days are needed or impossible to connect islands
        if (islands > 1 || islands == 0) {
            return 0; // Return 0 if already 0 or more than 1 island
        } else {
            // Check if removing any single block will make the grid disconnected
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j]) {
                        grid[i][j] = 0; // Temporarily remove this block
                        islands = count_islands(grid); // Recount the number of islands
                        grid[i][j] = 1; // Restore the block
                        // If removing this block causes more than 1 island, return 1
                        if (islands > 1 || islands == 0)
                            return 1;
                    }
                }
            }
        }
        return 2; // Return 2 if it requires removing more than one block
    }
};

/*
Approach:
1. The `minDays` function determines the minimum number of days needed to make all islands in the grid connected or to ensure there are no islands.
   - It first counts the number of islands in the grid using the `count_islands` function.
   - If the number of islands is more than 1 or 0, no changes are needed, so it returns 0.
   - If there is exactly 1 island, it checks if removing any single block would disconnect the island or create more than 1 island:
     - For each land cell, it temporarily removes the cell, recalculates the number of islands, and then restores the cell.
     - If removing a block increases the number of islands or results in no islands, it means that block was critical, and it returns 1.
   - If no single block removal can achieve this, it concludes that it requires removing more than one block, thus returning 2.

2. The `count_islands` function uses Depth-First Search (DFS) to explore and count connected components (islands) in the grid.
   - It marks visited cells and uses DFS to traverse all connected land cells.

Complexity Analysis:
- Time Complexity:
  - The `count_islands` function performs a DFS traversal of the grid, which is O(n * m), where n is the number of rows and m is the number of columns.
  - The `minDays` function involves checking each cell in the grid to see if removing it results in a change in the number of islands.
    - For each cell, it performs a DFS to count islands, which is O(n * m).
    - Since this is done for each cell, the worst-case time complexity for this operation is O(n * m * (n * m)) = O(n^2 * m^2).
  - Overall, the time complexity is dominated by the O(n^2 * m^2) term.

- Space Complexity:
  - The space complexity primarily depends on the storage for the visited grid and recursion stack for DFS.
  - The visited grid requires O(n * m) space.
  - The maximum recursion depth of DFS is O(n * m) in the worst case.
  - Therefore, the overall space complexity is O(n * m).
*/
