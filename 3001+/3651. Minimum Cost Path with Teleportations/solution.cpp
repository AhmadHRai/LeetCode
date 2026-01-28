const int MAX_VAL = 1e4 + 1; // Maximum possible value in grid
const int MAX_CELLS = 6400;  // Maximum number of cells in grid (r * c)
const int INF = 1e9 + 7;     // A large constant for initialization

// x_positions[x] holds the 1D indices of (i, j) grid positions with value 'x'
vector<int> x_positions[MAX_VAL];

// dp[t][idx] holds the minimum cost to reach (i, j) with t teleports
unsigned dp[11][MAX_CELLS];

// Suffix minimum values for each grid value x
unsigned suffix_min[MAX_VAL];

class Solution {
public:
    // Convert 2D index (i, j) to 1D index for easier array access
    static inline int get_index(int i, int j, int cols) {
        return i * cols + j;
    }

    static int minCost(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total_cells = rows * cols;

        int max_grid_value = 0;

        // Group grid cell positions by their values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cell_value = grid[i][j];
                x_positions[cell_value].push_back(get_index(i, j, cols));
                max_grid_value = max(max_grid_value, cell_value);
            }
        }

        // Initialize dp table with infinity
        for (int t = 0; t <= k; t++) {
            fill(dp[t], dp[t] + total_cells, INF);
        }

        // Base Case: No teleports, cost is computed step by step
        dp[0][0] = 0;  // Starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int pos = get_index(i, j, cols);
                int cell_value = grid[i][j];

                // Move from the top or left
                if (i > 0)
                    dp[0][pos] = min(dp[0][pos], dp[0][get_index(i - 1, j, cols)] + cell_value);
                if (j > 0)
                    dp[0][pos] = min(dp[0][pos], dp[0][get_index(i, j - 1, cols)] + cell_value);
            }
        }

        // DP with up to k teleports
        for (int t = 1; t <= k; t++) {
            // Compute suffixMin[x] for current teleport step
            unsigned current_min = INF;
            for (int x = max_grid_value; x >= 0; x--) {
                for (int index : x_positions[x]) {
                    current_min = min(current_min, dp[t - 1][index]);
                }
                suffix_min[x] = current_min; // Teleport to the minimum cost found
            }

            // Update the dp table for current teleport step
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int pos = get_index(i, j, cols);
                    int cell_value = grid[i][j];

                    // Best cost considering fewer teleports or teleporting
                    dp[t][pos] = min(dp[t - 1][pos], suffix_min[cell_value]);

                    // Move from the top or left
                    if (i > 0)
                        dp[t][pos] = min(dp[t][pos], dp[t][get_index(i - 1, j, cols)] + cell_value);
                    if (j > 0)
                        dp[t][pos] = min(dp[t][pos], dp[t][get_index(i, j - 1, cols)] + cell_value);
                }
            }
        }

        // The final answer is the minimum cost to reach the bottom-right corner
        int answer = dp[k][total_cells - 1];

        // Clear the x_positions for the next test case
        for (int x = 1; x <= max_grid_value; x++) {
            x_positions[x].clear();
        }

        return answer;
    }
};
