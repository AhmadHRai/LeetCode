class Solution {
public:
    // Declare the variables for the dimensions of the grid and the memoization table
    int m, n;
    int memo[50][50][51];
    // Define an array for the four directions: right, down, left, up
    int DIR[5] = {0, 1, 0, -1, 0};
    // This function returns the number of paths to move a ball out of the grid boundary
    // The grid has m rows and n columns
    // The ball can move at most maxMove times
    // The ball starts at the cell (startRow, startColumn)
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Assign the values of m and n to the class variables
        this->m = m; this->n = n;
        // Initialize the memoization table with -1
        memset(memo, -1, sizeof(memo));
        // Call the recursive function to find the paths from the starting cell
        return dp(startRow, startColumn, maxMove);
    }
    // This function returns the number of paths to move the ball out of the grid boundary
    // from the cell (r, c) with maxMove moves left
    int dp(int r, int c, int maxMove) {
        // Base case: if the ball is out of the grid, return 1
        if (r < 0 || r == m || c < 0 || c == n) return 1; // Out of bound -> Count 1 way
        // Base case: if the ball has no more moves left, return 0
        if (maxMove == 0) return 0;
        // If the memoization table has a valid value for the current state, return it
        if (memo[r][c][maxMove] != -1) return memo[r][c][maxMove];
        // Initialize the answer to zero
        int ans = 0;
        // Loop through the four directions
        for (int i = 0; i < 4; ++i)
            // Add the number of paths from the next cell in that direction with one less move
            // Modulo by a large prime number to avoid overflow
            ans = (ans + dp(r + DIR[i], c + DIR[i+1], maxMove - 1)) % 1000000007;
        // Store the answer in the memoization table and return it
        return memo[r][c][maxMove] = ans;
    }
};

/* 
Complexity:
    The time complexity is O(m * n * maxMove) as there are m * n * maxMove possible states, and each state takes O(1) time to compute. 
    The space complexity is O(m * n * maxMove) as well, as we need to store the memoization table and the recursion stack
 */