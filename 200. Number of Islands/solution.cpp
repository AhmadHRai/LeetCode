auto init = []() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 return 'c';
}();

class Solution {
    // Function to recursively remove an island starting from a given cell
    void removeIsland(short int i, short int j, vector<vector<char>> &grid)
    {
      short int m = grid.size(), n = grid[0].size();
      // Base case: return if the cell is out of bounds or not part of an island
      if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
        return;

      // Mark the current cell as not part of an island
      grid[i][j] = '0';
      // Recursively remove the island by visiting neighboring cells
      removeIsland(i, j + 1, grid); // Right
      removeIsland(i + 1, j, grid); // Down
      removeIsland(i, j - 1, grid); // Left
      removeIsland(i - 1, j, grid); // Up
    }
public:
    short int numIslands(vector<vector<char>>& grid) {
        short int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;

        // Iterate through each cell in the grid
        for (short int i = 0; i < m; i++)
        {
          for (short int j = 0; j < n; j++)
          {
            // If the current cell is part of an island
            if (grid[i][j] == '1')
            {
              islands++; // Increment the island count
              removeIsland(i, j, grid); // Remove the island starting from this cell
            }
          }
        }

        return islands; // Return the total number of islands
    }
};

/* 
Approach:
    The goal of this code is to count the number of islands in a 2D grid. An island is defined as a group of '1's connected 4-directionally (horizontal or vertical).

Algorithm:
    1. Initialize a counter `islands` to keep track of the number of islands.
    2. Iterate through each cell in the grid. If a cell contains a '1', increment `islands` and call `removeIsland` to mark all cells of the island as '0'.
    3. The `removeIsland` function is a recursive function that marks a cell as '0' (not part of an island) and then recursively calls itself for all neighboring cells that are part of the island.
    4. After iterating through all cells, return the value of `islands`.

Complexity:
    - Time complexity: O(n*m), where n and m are the dimensions of the grid. This is because in the worst case, we might need to visit every cell in the grid.
    - Space complexity: O(n*m) in the worst case, due to the recursive call stack. However, in practice, the space complexity is often much lower because the recursion depth is limited by the size of the largest island.
*/
