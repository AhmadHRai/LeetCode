class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell is part of an island
                if (grid[i][j] == '1') {
                    islands++; // Increment the island count
                    grid[i][j] = '0'; // Mark the current cell as visited
                    queue<pair<int, int>> todo; // Queue to perform BFS
                    todo.push({i, j}); // Add the current cell to the queue
                    // BFS to visit all cells connected to the current island
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        // Iterate through all four directions (right, down, left, up)
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            // Check if the neighboring cell is within bounds and part of an island
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0'; // Mark the neighboring cell as visited
                                todo.push({r, c}); // Add the neighboring cell to the queue
                            }
                        }
                    }
                }
            }
        }
        return islands; // Return the total number of islands
    }
};

/* 
Approach:
    The approach used in the code is to count the number of islands in a 2D grid. An island is defined as a group of '1's connected 4-directionally (horizontal or vertical). This is a common approach for solving this problem.

Algorithm:
    1. Initialize a counter `islands` to keep track of the number of islands.
    2. Iterate through each cell in the grid. If a cell contains a '1', increment `islands` and mark the cell as '0' (visited).
    3. Use a queue to perform a Breadth-First Search (BFS) starting from the current cell. For each cell visited, mark it as '0' and add its neighboring cells to the queue if they are part of an island.
    4. Continue the BFS until the queue is empty, which means all cells connected to the current island have been visited and marked.
    5. After iterating through all cells, return the value of `islands`.

Complexity:
- Time complexity: O(n*m), where n and m are the dimensions of the grid.
- Space complexity is O(m*n), where m and n are the dimensions of the grid
