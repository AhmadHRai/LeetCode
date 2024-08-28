class Solution {
public:
    // Function to count the number of sub-islands in grid2 that are also present in grid1
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(); // Number of rows in the grid
        int n = grid1[0].size(); // Number of columns in the grid
        vector<vector<int>> visited(m, vector<int>(n, 0)); // 2D vector to track visited cells
        int count = 0; // Counter for the number of sub-islands
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    // If the cell in grid2 is part of a new island and hasn't been visited
                    vector<pair<int, int>> cells = dfs(i, j, grid2, visited); // Get all cells of the island
                    if (isSubIsland(cells, grid1)) {
                        ++count; // Increment count if the island is a sub-island
                    }
                }
            }
        }
        
        return count; // Return the total count of sub-islands
    }

private:
    // Helper function for Depth-First Search to explore an island
    vector<pair<int, int>> dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        vector<pair<int, int>> cells; // Vector to store the cells of the current island
        stack<pair<int, int>> stk; // Stack for iterative DFS
        stk.push({r, c}); // Start DFS from the initial cell
        
        while (!stk.empty()) {
            auto [x, y] = stk.top(); // Get the top cell from the stack
            stk.pop(); // Remove the top cell from the stack
            
            // Skip out-of-bound cells, already visited cells, or cells with value 0
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == 0) 
                continue;
            
            visited[x][y] = 1; // Mark the cell as visited
            cells.push_back({x, y}); // Add the cell to the island's cell list
            
            // Push adjacent cells onto the stack
            stk.push({x + 1, y});
            stk.push({x - 1, y});
            stk.push({x, y + 1});
            stk.push({x, y - 1});
        }
        return cells; // Return the list of cells in the island
    }

    // Helper function to check if the island cells are all present in grid1
    bool isSubIsland(const vector<pair<int, int>>& cells, const vector<vector<int>>& grid1) {
        for (const auto& [x, y] : cells) {
            if (grid1[x][y] != 1) return false; // Check if each cell is also present in grid1
        }
        return true; // Return true if all cells are present in grid1
    }
};

/*
Approach Summary:
- Iterate over all cells in grid2. For each unvisited cell with value 1, use DFS to find all connected cells forming an island.
- Check if this island is a sub-island by verifying if all its cells have a value of 1 in grid1.
- Increment the count for each valid sub-island and return the total count.

Time Complexity:
- O(m * n), where m is the number of rows and n is the number of columns in the grid. Each cell is processed once during the DFS.

Space Complexity:
- O(m * n), where m is the number of rows and n is the number of columns in the grid. Space is used for the visited matrix, the stack for DFS, and the cells vector.
*/
