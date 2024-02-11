class Solution {
public:
    // Declare a 3D array to store the intermediate results of the subproblems
    int dp[70][70][70] = {};
    // This function takes a 2D grid representing a field of cherries and returns the maximum number of cherries that can be picked by two persons
    int cherryPickup(vector<vector<int>>& grid) {
        // Initialize the 3D array with -1 values
        memset(dp, -1, sizeof(dp));
        // Get the number of rows and columns of the grid
        int m = grid.size(), n = grid[0].size();
        // Call the helper function with the initial positions of the two persons
        return dfs(grid, m, n, 0, 0, n - 1);
    }
    // This helper function takes the grid, the number of rows and columns, the current row, and the current columns of the two persons, and returns the maximum number of cherries that can be picked from the current row to the bottom row
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        // If the current row is equal to the number of rows, return 0 as the base case
        if (r == m) return 0; // Reach to bottom row
        // If the 3D array has a non-negative value for the current positions, return that value as the memoized result
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        // Initialize a variable to store the maximum number of cherries
        int ans = 0;
        // Loop through the possible movements of the two persons, which are -1, 0, or 1 steps to the right or down
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Calculate the next columns of the two persons after the movement
                int nc1 = c1 + i, nc2 = c2 + j;
                // If the next columns are valid and not out of bounds
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    // Recursively call the helper function with the next row and columns, and update the maximum number of cherries with the returned value
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        // Calculate the number of cherries picked by the two persons at the current positions
        // If the two persons are at the same position, pick one cherry, otherwise pick two cherries
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        // Store the sum of the cherries and the maximum number of cherries in the 3D array for the current positions
        return dp[r][c1][c2] = ans + cherries;
    }
};


/* 
Approach:
    The code uses a dynamic programming approach to solve the problem of cherry pickup. Dynamic programming is a technique that breaks down a complex problem into smaller 
    subproblems and stores the results of the subproblems to avoid recomputation. The code uses a 3D array to store the results of the subproblems, which are the maximum number 
    of cherries that can be picked by two persons from a given row and columns to the bottom row. The code uses a recursive helper function to fill the 3D array with the results 
    of the subproblems, which are calculated by looping through the possible movements of the two persons and adding the cherries picked at the current positions. The code 
    returns the result of the helper function with the initial positions of the two persons as the final answer.

Complexity:
    The time complexity is O(m * n^2), where m is the number of rows and n is the number of columns in the grid. This is because the code uses a recursive helper function to iterate over the rows of the grid, and for each row, it loops through the possible movements of the two persons, which are O (n^2) in the worst case. The helper function also performs constant-time operations in each iteration.

    The space complexity is O(m * n^2), because the code uses a 3D array to store the results of the subproblems, which has a size of O (m * n^2) in the worst case. The helper function also uses recursion, but the depth of the recursion is bounded by the number of rows, which is O (m) in the worst case.
 */