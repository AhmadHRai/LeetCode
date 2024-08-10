class Solution {
public:
    // Depth-First Search (DFS) function to explore a region
    int dfs(vector<vector<int>> &g, int i, int j) {
        // Check if the position is out of bounds or already visited (non-zero)
        if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0)
            return 0; // If invalid or visited, return 0
        g[i][j] = 1; // Mark the cell as visited
        // Recursively visit all 4 possible directions (up, down, left, right)
        return 1 + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j - 1) + dfs(g, i, j + 1);
    }

    // Function to count the number of regions formed by slashes in the grid
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(); // Get the size of the grid
        int regions = 0; // Counter for the number of regions

        // Initialize a grid of size 3 times the input grid to account for subdivisions
        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));

        // Fill the grid based on the slashes in the input grid
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '/') 
                    // Set cells to 1 for '/' slashes
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
                else if (grid[i][j] == '\\') 
                    // Set cells to 1 for '\' slashes
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;

        // Traverse the entire grid and use DFS to count regions
        for (int i = 0; i < n * 3; ++i)
            for (int j = 0; j < n * 3; ++j)
                regions += dfs(g, i, j) ? 1 : 0; // Increment region count if DFS returns non-zero

        return regions; // Return the total number of regions
    }
};

// Fast input/output optimization
auto init = []() {
    ios::sync_with_stdio(false); // Disable synchronization with C standard streams for faster input/output
    cin.tie(nullptr); // Untie cin from cout
    cout.tie(nullptr); // Untie cout from cin
    return 'c'; // Return 'c' to satisfy the lambda's return type
}();

/*
Approach:
1. The `regionsBySlashes` function counts the number of regions in a grid that is formed by slashes ('/' and '\\') using a grid transformation and Depth-First Search (DFS).
   - It initializes a 3x3 grid for each cell in the input grid to accurately capture the effect of slashes on a finer grid.
   - Based on the type of slash ('/' or '\\'), it updates the appropriate cells in the 3x3 grid to mark boundaries.

2. The `dfs` function is used to explore all connected cells in the transformed grid. It marks cells as visited and recursively explores all four directions (up, down, left, right) to count the size of each connected region.

3. The main function iterates over every cell in the transformed grid and uses DFS to count distinct regions, adding to the total count whenever a new region is found.

Complexity Analysis:
- Time Complexity:
  - The time complexity for transforming the grid is O(n^2) where n is the size of the input grid.
  - The DFS function explores each cell once, leading to a complexity of O((3n)^2) = O(9n^2) = O(n^2).
  - Therefore, the overall time complexity is O(n^2) due to the dominant factors of the grid transformation and DFS traversal.

- Space Complexity:
  - The space complexity is primarily determined by the storage of the transformed grid and recursion stack.
  - The transformed grid requires O((3n)^2) = O(9n^2) = O(n^2) space.
  - The maximum depth of the recursion stack is also O(n^2) in the worst case.
  - Thus, the overall space complexity is O(n^2).
*/
