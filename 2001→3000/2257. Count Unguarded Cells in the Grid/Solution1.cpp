class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(m, vector<int> (n, 0));  // Create a grid v of size m x n initialized to 0
        int k = w.size();  // Get the number of guard positions
        for (int i = 0; i < k; i++) {  // Iterate over all guard positions
            int x = w[i][0], y = w[i][1];  // Get the coordinates of each guard
            v[x][y] = -2;  // Mark guard positions as -2 in the grid
        }
        
        k = g.size();  // Get the number of watchtower positions
        for (int i = 0; i < k; i++) {  // Iterate over all watchtower positions
            int x = g[i][0], y = g[i][1];  // Get the coordinates of each watchtower
            v[x][y] = 2;  // Mark watchtower positions as 2 in the grid
        }
        
        for (int j = 0; j < k; j++) {  // Iterate over all guard positions again to mark all guarded areas
            int x = g[j][0], y = g[j][1];  // Get the coordinates of each guard
            // Mark the upward direction (up)
            for (int i = x - 1; i >= 0; i--) {  // Iterate upwards from the guard position
                if (v[i][y] == -2 || v[i][y] == 2) break;  // Stop if we hit a guard or watchtower
                v[i][y] = 1;  // Mark the area as guarded
            }
            // Mark the downward direction (down)
            for (int i = x + 1; i < m; i++) {  // Iterate downwards from the guard position
                if (v[i][y] == -2 || v[i][y] == 2) break;  // Stop if we hit a guard or watchtower
                v[i][y] = 1;  // Mark the area as guarded
            }
            // Mark the left direction (left)
            for (int i = y - 1; i >= 0; i--) {  // Iterate leftwards from the guard position
                if (v[x][i] == -2 || v[x][i] == 2) break;  // Stop if we hit a guard or watchtower
                v[x][i] = 1;  // Mark the area as guarded
            }
            // Mark the right direction (right)
            for (int i = y + 1; i < n; i++) {  // Iterate rightwards from the guard position
                if (v[x][i] == -2 || v[x][i] == 2) break;  // Stop if we hit a guard or watchtower
                v[x][i] = 1;  // Mark the area as guarded
            }
        }
        
        int ans = 0;  // Initialize a counter for the unguarded cells
        for (int i = 0; i < m; i++) {  // Iterate through all rows of the grid
            for (int j = 0; j < n; j++) {  // Iterate through all columns of the grid
                if (!v[i][j]) ans++;  // If the cell is unguarded (i.e., v[i][j] == 0), increment the counter
            }
        }
        
        return ans;  // Return the total number of unguarded cells
    }
};

/*
Approach Summary:
- We are given a grid of size m x n with positions of guards and watchtowers.
- Each guard guards the area in four cardinal directions (up, down, left, right) and can only guard until a boundary (another guard or a watchtower).
- The watchtower is considered as a fixed point that blocks the guard's line of sight in the directions they are guarding.
- We first mark the positions of guards and watchtowers in the grid.
- Then, we iterate through the grid marking the areas that are guarded by the guards (based on their visibility directions).
- Finally, we count the number of cells that are unguarded, i.e., cells that have not been marked as guarded by either a guard or a watchtower.

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. We traverse the grid multiple times: once to mark guards and watchtowers, and then for each guard, we potentially traverse the grid in the four cardinal directions.
- Space Complexity: O(m * n), as we are storing a grid of size m x n to represent the status of each cell (guarded, unguarded, guard, or watchtower).
*/
