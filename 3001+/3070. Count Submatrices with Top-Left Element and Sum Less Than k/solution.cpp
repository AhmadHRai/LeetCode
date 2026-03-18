class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        int count = 0;

        // Build prefix sum matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = grid[i][j];
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        // Count all submatrices starting at (0,0)
        for (int r2 = 0; r2 < n; r2++) {
            for (int c2 = 0; c2 < m; c2++) {
                int sum = prefix[r2][c2]; // rectangle (0,0) to (r2,c2)
                if (sum <= k) count++;
            }
        }

        return count;
    }
};
