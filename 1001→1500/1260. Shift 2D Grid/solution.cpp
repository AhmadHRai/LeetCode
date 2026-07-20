class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int total = rows * cols;
        k %= total;

        if (k == 0) return grid;

        vector<vector<int>> res(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int originalIndex = r * cols + c;
                int newIndex = (originalIndex + k) % total;
                int newRow = newIndex / cols;
                int newCol = newIndex % cols;
                res[newRow][newCol] = grid[r][c];
            }
        }
        return res;
    }
};
