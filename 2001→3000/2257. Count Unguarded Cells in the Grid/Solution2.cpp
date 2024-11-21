static const int kds = []() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O streams for faster input/output
    cin.tie(nullptr); // Untie cin from cout to avoid flushing cout before reading input
    cout.tie(nullptr); // Untie cout from cin to avoid flushing cout after reading input
    return 0;
}(); // Static initializer for faster I/O

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g[m][n];  // Create a grid g of size m x n to represent the area
        memset(g, 0, sizeof(g));  // Initialize the grid to 0 (0 means unguarded)

        // Mark the guard and wall positions in the grid
        for (auto& e : guards) {  // Iterate through the guards' positions
            g[e[0]][e[1]] = 2;  // Mark guard positions as 2
        }
        for (auto& e : walls) {  // Iterate through the wall positions
            g[e[0]][e[1]] = 2;  // Mark wall positions as 2
        }

        int dirs[5] = {-1, 0, 1, 0, -1};  // Direction vectors for up, right, down, left (clockwise)

        // Iterate through each guard and mark the areas they can guard
        for (auto& e : guards) {  // Iterate through each guard
            for (int k = 0; k < 4; ++k) {  // Loop through the four directions (up, right, down, left)
                int x = e[0], y = e[1];  // Get the guard's position
                int a = dirs[k], b = dirs[k + 1];  // Get the current direction (a, b)
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    // Check if the next cell is within bounds and not a wall or another guard
                    x += a;  // Move in the current direction
                    y += b;  // Move in the current direction
                    g[x][y] = 1;  // Mark the area as guarded
                }
            }
        }

        int ans = 0;  // Initialize the answer (count of unguarded cells)
        for (auto& row : g) {  // Iterate through each row of the grid
            ans += count(row, row + n, 0);  // Count the number of unguarded cells (cells with value 0)
        }

        return ans;  // Return the total count of unguarded cells
    }
};

/*
Approach Summary:
- We are given a grid with positions of guards and walls. The goal is to find how many cells remain unguarded after all guards have marked their visibility areas.
- First, we initialize a grid `g` where each cell represents an area. Guards and walls are marked with `2`, and other cells are initialized to `0` (unguarded).
- The guards' visibility spreads in four directions (up, right, down, left), and we mark cells as guarded (1) as they fall within the guard's line of sight, stopping when blocked by a wall or another guard.
- Finally, we count the number of cells in the grid that are still unguarded (cells with value 0).

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. The guard visibility is processed for each direction, and each guard's movement is bounded by the grid size.
- Space Complexity: O(m * n), as we are using a grid of size m x n to represent the status of each cell (unguarded, guarded, wall, or guard).
*/
