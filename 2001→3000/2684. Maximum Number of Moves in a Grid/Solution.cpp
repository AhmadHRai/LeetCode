class Solution {
public:
    // Function to find the maximum number of moves in the grid
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(); // Get the number of rows in the grid
        int n = grid[0].size(); // Get the number of columns in the grid

        // Directions to move right, down-right, and up-right
        vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
        
        // Create a cache for memoization initialized to -1
        vector<vector<int>> cache(m, vector<int>(n, -1));

        // Lambda function for dynamic programming
        function<int(int, int)> dp = [&](int i, int j) {
            // Return cached value if already computed
            if (cache[i][j] != -1) return cache[i][j];
            int ans = 0; // Initialize the answer for this cell

            // Explore the three possible directions
            for (auto [x, y] : dirs) {
                int ni = i + x, nj = j + y; // New indices after moving
                // Check boundaries and ensure the next cell is greater
                if (ni >= 0 && ni < m && nj < n && grid[i][j] < grid[ni][nj])
                    ans = max(ans, 1 + dp(ni, nj)); // Update answer with max moves
            }
            return cache[i][j] = ans; // Store the computed answer in cache
        };
        
        int res = 0; // Initialize the result variable
        
        // Try starting from each cell in the first column
        for (int i = 0; i < m; i++)
            res = max(res, dp(i, 0)); // Update the result with the maximum moves
        
        return res; // Return the maximum moves found
    }
};

/*
Approach:

    The solution uses dynamic programming with memoization to calculate the maximum moves from each cell in the grid. 
    It starts from the first column and explores three potential moves (to the right, down-right, and up-right) using a recursive function `dp`. 
    The results of previous calculations are stored in a cache to avoid redundant computations, enhancing efficiency.

Complexity:

    Time Complexity: O(m * n), where m is the number of rows and n is the number of columns. Each cell in the grid is processed once, and the memoization ensures each call to dp runs in constant time after the initial computation.

    Space Complexity: O(m * n) for the cache used to store results of subproblems. 

This approach efficiently determines the maximum number of moves possible in the given grid while adhering to the constraints of movement.
*/
