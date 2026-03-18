class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // Compute 2D prefix sum in-place
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) grid[i][j] += grid[i - 1][j]; // add above
                if (j > 0) grid[i][j] += grid[i][j - 1]; // add left
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1]; // remove double-count
            }
        }

        // Count all submatrices starting at (0,0) with sum <= k
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] <= k) count++;

        return count;
    }
};
